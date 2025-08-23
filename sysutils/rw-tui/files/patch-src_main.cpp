--- src/main.cpp.orig	2023-07-30 15:32:56 UTC
+++ src/main.cpp
@@ -5,6 +5,9 @@
 #include <unistd.h>
 #include <vector>
 
+#include <iostream>
+using namespace std;
+
 #include "ftxui/component/captured_mouse.hpp"
 #include "ftxui/component/component.hpp"
 #include "ftxui/component/component_base.hpp"
@@ -25,7 +28,13 @@
 #include "utils/is_file_exist.hpp"
 
 #define DEV_MEM "/dev/mem"
-#define DEV_FMEM "/dev/fmem"
+#if defined(__linux__)
+#  define DEV_FMEM "/dev/fmem"
+#elif defined(__FreeBSD__)
+#  define DEV_KMEM "/dev/kmem"
+#else
+#  error "Unsupported OS"
+#endif
 
 using namespace std;
 using namespace ftxui;
@@ -71,6 +80,7 @@ int main(int argc, char *argv[]) {
   gShowMessageModal = &showMessageModal;
   gMessageStr = &messageStr;
 
+#if defined(__linux__)
   if (isFileExist(DEV_FMEM) == false) {
     if (isFileExist(DEV_MEM) == false) {
       cerr << "[ERROR] Neither /dev/mem nor /dev/fmem exist.\nGet the source "
@@ -90,9 +100,21 @@ int main(int argc, char *argv[]) {
       return EXIT_FAILURE;
     }
   }
+#elif defined(__FreeBSD__)
+  if (isFileExist(DEV_MEM) == false /*|| isFileExist(DEV_KMEM) == false*/) {
+      cerr << "[ERROR] Either /dev/mem or /dev/kmem doesn't exist.\n"
+              "Please check if the kernel was configured with 'device mem'."
+           << endl;
+      return EXIT_FAILURE;
+  }
+#endif
 
   int fileDescriptor;
+#if defined(__linux__)
   if ((fileDescriptor = open(DEV_FMEM, O_RDWR | O_SYNC)) == -1)
+#elif defined(__FreeBSD__)
+  if ((fileDescriptor = open(DEV_MEM, O_RDWR | O_SYNC)) == -1)
+#endif
     FATAL;
   gFileDescriptor = &fileDescriptor;
 
@@ -102,7 +124,7 @@ int main(int argc, char *argv[]) {
   int tabSelected = 0;
   vector<string> tabValues{
       " Memory ",
-      " PCI ",
+      //" PCI ",
   };
   auto tabToggle =
       Menu(&tabValues, &tabSelected, MenuOption::Horizontal()) | border;
@@ -110,7 +132,7 @@ int main(int argc, char *argv[]) {
   Component tabContainer = Container::Tab(
       {
           (new Memory(0x00000000))->getComponent(),
-          (new PCI(*gBaseAddress))->getComponent(),
+          //(new PCI(*gBaseAddress))->getComponent(),
       },
       &tabSelected);
 
@@ -140,4 +162,4 @@ int main(int argc, char *argv[]) {
               center);
   close(fileDescriptor);
   return EXIT_SUCCESS;
-}
\ No newline at end of file
+}
