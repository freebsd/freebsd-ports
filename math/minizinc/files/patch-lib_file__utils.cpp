--- lib/file_utils.cpp.orig	2020-10-25 18:29:35 UTC
+++ lib/file_utils.cpp
@@ -310,6 +310,9 @@ std::string share_directory() {
     return std::string(MZNSTDLIBDIR);
   }
 #endif
+#if defined(__FreeBSD__)
+  return FREEBSD_MZN_STDLIB_DIR;
+#else
   std::string mypath = FileUtils::progpath();
   int depth = 0;
   for (char i : mypath) {
@@ -324,6 +327,7 @@ std::string share_directory() {
     mypath += "/..";
   }
   return "";
+#endif
 }
 
 std::string user_config_dir() {
