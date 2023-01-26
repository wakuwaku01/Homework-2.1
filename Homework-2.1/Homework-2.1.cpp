#include <fstream>
#include <iostream>

void change_arr1(int* arr1, int size1) {
    for (int i = 0; i < size1 - 1; i++) {
        int t = arr1[i];
        arr1[i] = arr1[i + 1];
        arr1[i + 1] = t;
    }
}

void change_arr2(int* arr2, int size2) {
    for (int i = size2 - 1; i > 0; i--) {
        int t = arr2[i];
        arr2[i] = arr2[i - 1];
        arr2[i - 1] = t;
    }
}

int main() {
    std::string in_string;
    int size1 = 0, size2 = 0;

    std::ifstream fin("in.txt");
    if (!fin.is_open()) {
        std::cout << "Не удалось открыть файл." << std::endl;
    }
    else {
        fin >> size1;

        int* arr1 = new int[size1];
        for (int i = 0; i < size1; i++) {
            fin >> arr1[i];
        }
        fin >> size2;

        int* arr2 = new int[size2];
        for (int i = 0; i < size2; i++) {
            fin >> arr2[i];
        }
        fin.close();

        change_arr1(arr1, size1);
        change_arr2(arr2, size2);

        std::ofstream fout("out.txt");
        if (!fout.is_open()) {
            std::cout << "Не удалось открыть файл." << std::endl;
        }
        else {
            fout << size2 << std::endl;
            for (int i = 0; i < size2; i++) {
                fout << arr2[i] << " ";
            }
            fout << std::endl;

            fout << size1 << std::endl;
            for (int i = 0; i < size1; i++) {
                fout << arr1[i] << " ";
            }
            fout << std::endl;
        }
        fout.close();
        /*
        
        for (int i = 0; i < size1; i++) {
            std::cout << arr1[i] << " ";
        }
        std::cout << std::endl;

        for (int i = 0; i < size2; i++) {
            std::cout << arr2[i] << " ";
        }
        std::cout << std::endl;
        */
        delete[] arr1;
        delete[] arr2;
    }
}