--- ./base/file_util_posix.cc.orig	2010-12-16 02:11:49.000000000 +0100
+++ ./base/file_util_posix.cc	2010-12-20 20:15:07.000000000 +0100
@@ -815,7 +815,11 @@
 }
 
 bool GetShmemTempDir(FilePath* path) {
+#if defined(OS_LINUX)
   *path = FilePath("/dev/shm");
+#else
+  *path = FilePath("/tmp");
+#endif
   return true;
 }
 
