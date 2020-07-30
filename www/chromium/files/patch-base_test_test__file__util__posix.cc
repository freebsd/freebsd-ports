--- base/test/test_file_util_posix.cc.orig	2020-07-07 21:57:30 UTC
+++ base/test/test_file_util_posix.cc
@@ -85,7 +85,7 @@ void SyncPageCacheToDisk() {
   sync();
 }
 
-#if !defined(OS_LINUX) && !defined(OS_MACOSX) && !defined(OS_ANDROID)
+#if !defined(OS_LINUX) && !defined(OS_MACOSX) && !defined(OS_ANDROID) && !defined(OS_BSD)
 bool EvictFileFromSystemCache(const FilePath& file) {
   // There doesn't seem to be a POSIX way to cool the disk cache.
   NOTIMPLEMENTED();
