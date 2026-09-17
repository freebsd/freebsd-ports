-- override lib path with FREEBSD_MZN_STDLIB_DIR

--- lib/file_utils.cpp.orig	2026-08-30 23:54:04 UTC
+++ lib/file_utils.cpp
@@ -403,6 +403,9 @@ std::string share_directory() {
   if (FileUtils::file_exists(static_stdlib_dir + "/std/stdlib.mzn")) {
     return static_stdlib_dir;
   }
+#if defined(__FreeBSD__)
+  return FREEBSD_MZN_STDLIB_DIR;
+#else
   std::string mypath = FileUtils::progpath();
   int depth = 0;
   for (char i : mypath) {
@@ -417,6 +420,7 @@ std::string share_directory() {
     mypath += "/..";
   }
   return "";
+#endif
 }
 
 std::string user_config_dir() {
