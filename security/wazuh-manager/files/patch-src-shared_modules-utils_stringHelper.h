--- src/shared_modules/utils/stringHelper.h	2023-12-09 01:08:14.397366000 -0500
+++ src/shared_modules/utils/stringHelper.h	2023-12-09 12:07:52.155984000 -0500
@@ -210,6 +210,17 @@
         return leftTrim(rightTrim(str, args), args);
     }
 
+    static std::string trimToOneSpace(const std::string& str)
+    {
+	std::string str_output;
+
+	str_output.clear();
+        std::unique_copy (str.begin(), str.end(), std::back_insert_iterator<std::string>(str_output),
+                                     [](char a,char b){ return std::isspace(a) && std::isspace(b);});
+
+        return str_output;
+    }
+
     static std::string toUpperCase(const std::string& str)
     {
         std::string temp{ str };
@@ -219,6 +230,19 @@
                        [](std::string::value_type character)
         {
             return std::toupper(character);
+        });
+        return temp;
+    }
+
+    static std::string toLowerCase(const std::string& str)
+    {
+        std::string temp{ str };
+        std::transform(std::begin(temp),
+                       std::end(temp),
+                       std::begin(temp),
+                       [](std::string::value_type character)
+        {
+            return std::tolower(character);
         });
         return temp;
     }
