--- src/3rdparty/chromium/base/test/test_file_util_linux.cc.orig	2023-09-13 12:11:42 UTC
+++ src/3rdparty/chromium/base/test/test_file_util_linux.cc
@@ -54,8 +54,10 @@ bool EvictFileFromSystemCache(const FilePath& file) {
     return false;
   if (fdatasync(fd.get()) != 0)
     return false;
+#if !BUILDFLAG(IS_BSD)
   if (posix_fadvise(fd.get(), 0, 0, POSIX_FADV_DONTNEED) != 0)
     return false;
+#endif
   return true;
 }
 
