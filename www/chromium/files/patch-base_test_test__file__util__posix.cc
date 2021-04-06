--- base/test/test_file_util_posix.cc.orig	2021-03-12 23:57:15 UTC
+++ base/test/test_file_util_posix.cc
@@ -87,7 +87,7 @@ void SyncPageCacheToDisk() {
   sync();
 }
 
-#if !defined(OS_LINUX) && !defined(OS_CHROMEOS) && !defined(OS_APPLE) && \
+#if !defined(OS_LINUX) && !defined(OS_CHROMEOS) && !defined(OS_APPLE) && !defined(OS_BSD) && \
     !defined(OS_ANDROID)
 bool EvictFileFromSystemCache(const FilePath& file) {
   // There doesn't seem to be a POSIX way to cool the disk cache.
