--- base/test/test_file_util_posix.cc.orig	2017-09-05 21:05:11.000000000 +0200
+++ base/test/test_file_util_posix.cc	2017-09-06 16:59:12.993711000 +0200
@@ -79,7 +79,7 @@
   return DeleteFile(file, recurse);
 }
 
-#if !defined(OS_LINUX) && !defined(OS_MACOSX) && !defined(OS_ANDROID)
+#if !defined(OS_LINUX) && !defined(OS_MACOSX) && !defined(OS_ANDROID) && !defined(OS_BSD)
 bool EvictFileFromSystemCache(const FilePath& file) {
   // There doesn't seem to be a POSIX way to cool the disk cache.
   NOTIMPLEMENTED();
