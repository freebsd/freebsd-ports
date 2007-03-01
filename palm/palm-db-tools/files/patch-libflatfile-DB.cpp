--- libflatfile/DB.cpp.orig	Thu Jun 19 16:37:46 2003
+++ libflatfile/DB.cpp
@@ -511,7 +511,8 @@
                             f.type = PalmLib::FlatFile::Field::LIST;
                 if (!field(j).argument().empty()) {
                     std::string data = field(j).argument();
-                    unsigned int k, pos = 0;
+                    unsigned int k;
+                    size_t pos = 0;
                     pi_uint16_t itemID = *ptrs[j]; // TR: a list value is stored on 1 byte
 
                     for (k = 0; k < itemID; k++) {
@@ -716,7 +717,8 @@
         case PalmLib::FlatFile::Field::LIST:
         if (!field(i).argument().empty()) {
             std::string data = field(i).argument();
-            unsigned int pos = 0, next, j = 0;
+            size_t pos = 0, next;
+            unsigned int j = 0;
             pi_int16_t itemID = -1;
 
             while ( (next = data.find(charSeperator, pos)) != std::string::npos) {
@@ -920,7 +922,7 @@
             if (!field(i).argument().empty()) {
                 std::string data = field(i).argument();
                 std::vector<std::string> items;
-                unsigned int pos = 0, next;
+                size_t pos = 0, next;
                 std::vector<std::string>::iterator iter;
                 size = 2 + 2 * sizeof(pi_uint16_t);
                 while ( (next = data.find(charSeperator, pos)) != std::string::npos) {
