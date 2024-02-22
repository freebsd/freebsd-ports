--- tools/snort2lua/helpers/s2l_util.cc.orig	2024-02-22 01:22:58 UTC
+++ tools/snort2lua/helpers/s2l_util.cc
@@ -103,13 +103,13 @@ std::string& ltrim(std::string& s)
 
 std::string& ltrim(std::string& s)
 {
-    s.erase(s.begin(), std::find_if(s.begin(), s.end(), std::not_fn(std::ptr_fun<int, int>(std::isspace))));
+    s.erase(s.begin(), std::find_if(s.begin(), s.end(), [](int c) {return !std::isspace(c);}));
     return s;
 }
 
 std::string& rtrim(std::string& s)
 {
-    s.erase(std::find_if(s.rbegin(), s.rend(), std::not_fn(std::ptr_fun<int, int>(std::isspace))).base(), s.end());
+    s.erase(std::find_if(s.rbegin(), s.rend(), [](int c) {return !std::isspace(c);}).base(), s.end());
     return s;
 }
 
