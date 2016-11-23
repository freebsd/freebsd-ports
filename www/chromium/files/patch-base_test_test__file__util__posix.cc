--- base/test/test_file_util_posix.cc.orig	2016-10-06 04:02:08.000000000 +0300
+++ base/test/test_file_util_posix.cc	2016-10-25 21:44:27.287523000 +0300
@@ -79,7 +79,7 @@
   return DeleteFile(file, recurse);
 }
 
-#if !defined(OS_LINUX) && !defined(OS_MACOSX)
+#if !defined(OS_LINUX) && !defined(OS_MACOSX) && !defined(OS_BSD)
 bool EvictFileFromSystemCache(const FilePath& file) {
   // There doesn't seem to be a POSIX way to cool the disk cache.
   NOTIMPLEMENTED();
