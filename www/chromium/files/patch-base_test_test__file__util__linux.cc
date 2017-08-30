--- base/test/test_file_util_linux.cc.orig	2017-08-10 16:14:03.505570000 +0200
+++ base/test/test_file_util_linux.cc	2017-08-10 16:14:43.299690000 +0200
@@ -20,8 +20,10 @@
     return false;
   if (fdatasync(fd.get()) != 0)
     return false;
+#if !defined(OS_BSD)
   if (posix_fadvise(fd.get(), 0, 0, POSIX_FADV_DONTNEED) != 0)
     return false;
+#endif
   return true;
 }
 
