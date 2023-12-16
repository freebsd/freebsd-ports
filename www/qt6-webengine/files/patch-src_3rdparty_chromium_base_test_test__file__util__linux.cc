--- src/3rdparty/chromium/base/test/test_file_util_linux.cc.orig	2022-02-28 16:54:41 UTC
+++ src/3rdparty/chromium/base/test/test_file_util_linux.cc
@@ -54,8 +54,10 @@ bool EvictFileFromSystemCache(const FilePath& file) {
     return false;
   if (fdatasync(fd.get()) != 0)
     return false;
+#if !defined(OS_BSD)
   if (posix_fadvise(fd.get(), 0, 0, POSIX_FADV_DONTNEED) != 0)
     return false;
+#endif
   return true;
 }
 
