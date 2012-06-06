--- src/mlib/filesystem.cpp.orig	2012-06-05 18:44:31.000000000 +0200
+++ src/mlib/filesystem.cpp	2012-06-05 18:46:42.000000000 +0200
@@ -47,7 +47,7 @@
 
 std::string get_basename(const fs::path& pth)
 {
-    std::string name_s = pth.leaf();
+    std::string name_s = pth.filename().string();
     const char* name = name_s.c_str();
 
     //if( const char* dot = strstr(name, ".") )
@@ -58,7 +58,7 @@
 
 std::string get_extension(const fs::path& pth)
 {
-    std::string name_s = pth.leaf();
+    std::string name_s = pth.filename().string();
 
     if( const char* dot = FindExtDot(name_s.c_str()) )
         return std::string(dot+1);
@@ -72,7 +72,6 @@
     tune_boost_filesystem()
     {
         // чтоб любые символы в именах файлов позволялись, для utf8
-        fs::path::default_name_check(fs::native);
     }
 } tune_boost_filesystem_obj;
 
