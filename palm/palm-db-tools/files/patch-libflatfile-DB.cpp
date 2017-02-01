--- libflatfile/DB.cpp.orig	Thu Jun 19 16:37:46 2003
+++ libflatfile/DB.cpp
@@ -221,7 +221,7 @@ void PalmLib::FlatFile::DB::extract_list
             throw PalmLib::error("list view is corrupt");
 
         // Determine the length of the name string.
-        pi_char_t* null_ptr = reinterpret_cast<pi_char_t*>
+        const pi_char_t* null_ptr = reinterpret_cast<const pi_char_t*>
             (memchr(chunk.data() + 4, 0, 32));
         if (null_ptr)
             lv.name = std::string((char *) (chunk.data() + 4),
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
