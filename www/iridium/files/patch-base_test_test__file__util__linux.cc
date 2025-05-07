--- base/test/test_file_util_linux.cc.orig	2025-05-07 06:48:23 UTC
+++ base/test/test_file_util_linux.cc
@@ -56,9 +56,11 @@ bool EvictFileFromSystemCache(const FilePath& file) {
   if (fdatasync(fd.get()) != 0) {
     return false;
   }
+#if !BUILDFLAG(IS_BSD)
   if (posix_fadvise(fd.get(), 0, 0, POSIX_FADV_DONTNEED) != 0) {
     return false;
   }
+#endif
   return true;
 }
 
