#include <iostream>
#include <vector>
#include <fstream>
#include <iomanip>
#include <string>
#include <limits>

using namespace std;

struct Student {
    int id;
    string name;
    double grade;
};

vector<Student> students;

void clearInput() {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

void addStudent() {
    Student s;

    cout << "\n--- Add Student ---\n";

    cout << "Student ID: ";
    while (!(cin >> s.id)) {
        cout << "Invalid ID. Enter a number: ";
        clearInput();
    }
    clearInput();

    cout << "Student Name: ";
    getline(cin, s.name);

    cout << "Grade (0-100): ";
    while (!(cin >> s.grade) || s.grade < 0 || s.grade > 100) {
        cout << "Invalid grade. Enter 0-100: ";
        clearInput();
    }

    students.push_back(s);

    cout << "\nStudent added successfully!\n";
}

void showStudents() {
    cout << "\n========== STUDENT LIST ==========\n";

    if (students.empty()) {
        cout << "No students found.\n";
        return;
    }

    cout << left
         << setw(10) << "ID"
         << setw(25) << "Name"
         << setw(10) << "Grade" << endl;

    cout << "---------------------------------------------\n";

    for (const Student& s : students) {
        cout << left
             << setw(10) << s.id
             << setw(25) << s.name
             << setw(10) << s.grade << endl;
    }
}

void searchStudent() {
    int id;

    cout << "\nEnter Student ID: ";
    cin >> id;

    for (const Student& s : students) {
        if (s.id == id) {
            cout << "\nStudent found!\n";
            cout << "ID: " << s.id << endl;
            cout << "Name: " << s.name << endl;
            cout << "Grade: " << s.grade << endl;
            return;
        }
    }

    cout << "\nStudent not found.\n";
}

void deleteStudent() {
    int id;

    cout << "\nEnter Student ID to delete: ";
    cin >> id;

    for (auto it = students.begin(); it != students.end(); ++it) {
        if (it->id == id) {
            students.erase(it);
            cout << "\nStudent deleted successfully!\n";
            return;
        }
    }

    cout << "\nStudent not found.\n";
}

void saveStudents() {
    ofstream file("students.txt");

    for (const Student& s : students) {
        file << s.id << "|"
             << s.name << "|"
             << s.grade << endl;
    }

    file.close();

    cout << "\nData saved to students.txt\n";
}

int main() {
    int choice;

    do {
        cout << "\n=================================\n";
        cout << "   STUDENT MANAGEMENT SYSTEM\n";
        cout << "=================================\n";
        cout << "1. Add Student\n";
        cout << "2. Show Students\n";
        cout << "3. Search Student\n";
        cout << "4. Delete Student\n";
        cout << "5. Save Data\n";
        cout << "0. Exit\n";
        cout << "=================================\n";
        cout << "Choose an option: ";

        cin >> choice;

        switch (choice) {
            case 1:
                addStudent();
                break;

            case 2:
                showStudents();
                break;

            case 3:
                searchStudent();
                break;

            case 4:
                deleteStudent();
                break;

            case 5:
                saveStudents();
                break;

            case 0:
                cout << "\nGoodbye!\n";
                break;

            default:
                cout << "\nInvalid option!\n";
        }

    } while (choice != 0);

    return 0;
}