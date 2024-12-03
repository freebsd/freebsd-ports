--- src/shared_modules/utils/stringHelper.h.orig	2024-10-17 00:22:27.000000000 -0700
+++ src/shared_modules/utils/stringHelper.h	2024-10-19 23:58:11.231439000 -0700
@@ -256,6 +256,17 @@
         return ret;
     }
 
+    static std::string trimToOneSpace(const std::string& str)
+    {
+       std::string str_output;
+
+       str_output.clear();
+        std::unique_copy (str.begin(), str.end(), std::back_insert_iterator<std::string>(str_output),
+                                     [](char a,char b){ return std::isspace(a) && std::isspace(b);});
+
+        return str_output;
+    }
+
     static std::string toUpperCase(const std::string& str)
     {
         std::string temp {str};
