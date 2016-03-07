--- src/mlib/filesystem.cpp.orig	2013-03-07 21:20:45 UTC
+++ src/mlib/filesystem.cpp
@@ -105,7 +105,7 @@ std::string get_extension(const fs::path
 
 std::string get_basename(const fs::path& pth)
 {
-    std::string name_s = pth.leaf();
+    std::string name_s = pth.filename().string();
     const char* name = name_s.c_str();
 
     //if( const char* dot = strstr(name, ".") )
@@ -116,7 +116,7 @@ std::string get_basename(const fs::path&
 
 std::string get_extension(const fs::path& pth)
 {
-    std::string name_s = pth.leaf();
+    std::string name_s = pth.filename().string();
 
     if( const char* dot = FindExtDot(name_s.c_str()) )
         return std::string(dot+1);
