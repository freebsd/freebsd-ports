--- base/test/test_file_util_posix.cc.orig	2017-04-19 19:06:28 UTC
+++ base/test/test_file_util_posix.cc
@@ -79,7 +79,7 @@ bool DieFileDie(const FilePath& file, bo
   return DeleteFile(file, recurse);
 }
 
-#if !defined(OS_LINUX) && !defined(OS_MACOSX)
+#if !defined(OS_LINUX) && !defined(OS_MACOSX) && !defined(OS_BSD)
 bool EvictFileFromSystemCache(const FilePath& file) {
   // There doesn't seem to be a POSIX way to cool the disk cache.
   NOTIMPLEMENTED();
