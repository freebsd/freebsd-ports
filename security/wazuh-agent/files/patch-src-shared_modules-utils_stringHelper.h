--- src/shared_modules/utils/stringHelper.h	2025-09-23 06:59:40.000000000 -0700
+++ src/shared_modules/utils/stringHelper.h	2025-10-16 14:04:29.575997000 -0700
@@ -19,6 +19,7 @@
 #include <sstream>
 #include <string>
 #include <vector>
+#include <map>
 #if __cplusplus >= 201703L
 #include <string_view>
 #endif
@@ -150,6 +151,15 @@
         return haystack;
     }
 
+    static std::string join(const std::vector<std::string>& vec, const std::string& delimiter) {
+       std::ostringstream joinResult;
+       for (size_t i = 0; i < vec.size(); ++i) {
+           joinResult << vec[i];
+           if (i != vec.size() - 1) joinResult << delimiter;
+       }
+       return joinResult.str();
+    }
+
     static std::vector<std::string> split(const std::string& str, const char delimiter)
     {
         std::vector<std::string> tokens;
@@ -257,6 +267,17 @@
 
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
