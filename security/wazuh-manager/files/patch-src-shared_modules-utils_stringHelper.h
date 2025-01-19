--- src/shared_modules/utils/stringHelper.h	2025-01-08 01:15:05.000000000 -0800
+++ src/shared_modules/utils/stringHelper.h	2025-01-14 21:32:26.067988000 -0800
@@ -19,6 +19,7 @@
 #include <sstream>
 #include <string>
 #include <vector>
+#include <map>
 
 #pragma GCC diagnostic push
 #pragma GCC diagnostic ignored "-Wunused-function"
@@ -254,6 +255,17 @@
 
         // LCOV_EXCL_STOP
         return ret;
+    }
+
+    static std::string trimToOneSpace(const std::string& str)
+    {
+       std::string str_output;
+
+       str_output.clear();
+        std::unique_copy (str.begin(), str.end(), std::back_insert_iterator<std::string>(str_output),
+                                     [](char a,char b){ return std::isspace(a) && std::isspace(b);});
+
+        return str_output;
     }
 
     static std::string toUpperCase(const std::string& str)
