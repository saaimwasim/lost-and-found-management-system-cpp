#include <iostream>
#include <string>
using namespace std;

struct lostItem {
    string itemName;
    string location;
    string date;
    string finder;
    string fcontact;
};

lostItem items[50];
int total = 0;

int main() {
    int choice;

    do {
        cout << "\n--- Lost & Found Management System ---\n";
        cout << "\n1. Add a lost item\n";
        cout << "2. View all items\n";
        cout << "3. Search item\n";
        cout << "4. Update item\n";
        cout << "5. Delete item\n";
        cout << "6. Exit\n";

        cout << "\nEnter Choice: ";
        cin >> choice;

        // Create
        if (choice == 1) {
            if (total >= 50) {
                cout << "\nStorage is full. Cannot add more items.\n";
            }
            else {
                cin.ignore();

                cout << "Item Name: ";
                getline(cin, items[total].itemName);

                cout << "Location Found: ";
                getline(cin, items[total].location);

                cout << "Date Found: ";
                getline(cin, items[total].date);

                cout << "Finder Name: ";
                getline(cin, items[total].finder);

                cout << "Finder Contact: ";
                getline(cin, items[total].fcontact);

                total++;
                cout << "\nItem added successfully.\n";
            }
        }

        // Read
        else if (choice == 2) {
            if (total == 0) {
                cout << "\nNo records found.\n";
            }
            else {
                for (int i = 0; i < total; i++) {
                    cout << "\nItem " << i + 1 << endl;
                    cout << "Item Name: " << items[i].itemName << endl;
                    cout << "Location Found: " << items[i].location << endl;
                    cout << "Date Found: " << items[i].date << endl;
                    cout << "Finder Name: " << items[i].finder << endl;
                    cout << "Finder Contact: " << items[i].fcontact << endl;
                }
            }
        }

        // Search
        else if (choice == 3) {
            string name;
            bool found = false;

            cin.ignore();
            cout << "\nEnter Item Name to Search: ";
            getline(cin, name);

            for (int i = 0; i < total; i++) {
                if (items[i].itemName == name) {
                    cout << "\nItem Found\n";
                    cout << "Item Name: " << items[i].itemName << endl;
                    cout << "Location Found: " << items[i].location << endl;
                    cout << "Date Found: " << items[i].date << endl;
                    cout << "Finder Name: " << items[i].finder << endl;
                    cout << "Finder Contact: " << items[i].fcontact << endl;

                    found = true;
                    break;
                }
            }

            if (!found) {
                cout << "\nItem Not Found\n";
            }
        }

        // Update
        else if (choice == 4) {
            string name;
            bool found = false;

            cin.ignore();
            cout << "\nEnter Item Name to Update: ";
            getline(cin, name);

            for (int i = 0; i < total; i++) {
                if (items[i].itemName == name) {
                    cout << "\nNew Location: ";
                    getline(cin, items[i].location);

                    cout << "New Date: ";
                    getline(cin, items[i].date);

                    cout << "New Finder Name: ";
                    getline(cin, items[i].finder);

                    cout << "New Finder Contact: ";
                    getline(cin, items[i].fcontact);

                    found = true;
                    cout << "\nItem Updated Successfully.\n";
                    break;
                }
            }

            if (!found) {
                cout << "\nItem Not Found. Update Failed!\n";
            }
        }

        // Delete
        else if (choice == 5) {
            string name;
            bool found = false;

            cin.ignore();
            cout << "\nEnter Item Name to Delete: ";
            getline(cin, name);

            for (int i = 0; i < total; i++) {
                if (items[i].itemName == name) {
                    for (int j = i; j < total - 1; j++) {
                        items[j] = items[j + 1];
                    }

                    total--;
                    found = true;
                    cout << "\nItem Deleted Successfully.\n";
                    break;
                }
            }

            if (!found) {
                cout << "\nItem Not Found. Delete Failed!\n";
            }
        }

        else if (choice == 6) {
            cout << "\nExiting program. Thank you!\n";
        }

        else {
            cout << "\nInvalid choice. Please try again.\n";
        }

    } while (choice != 6);

    return 0;
}
