--- lib/file_utils.cpp.orig	2020-11-09 03:26:53 UTC
+++ lib/file_utils.cpp
@@ -315,6 +315,9 @@ std::string share_directory() {
   if (FileUtils::file_exists(static_stdlib_dir + "/std/stdlib.mzn")) {
     return static_stdlib_dir;
   }
+#if defined(__FreeBSD__)
+  return FREEBSD_MZN_STDLIB_DIR;
+#else
   std::string mypath = FileUtils::progpath();
   int depth = 0;
   for (char i : mypath) {
@@ -329,6 +332,7 @@ std::string share_directory() {
     mypath += "/..";
   }
   return "";
+#endif
 }
 
 std::string user_config_dir() {
