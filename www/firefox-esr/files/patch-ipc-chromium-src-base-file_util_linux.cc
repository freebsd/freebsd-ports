--- ipc/chromium/src/base/file_util_linux.cc~
+++ ipc/chromium/src/base/file_util_linux.cc
@@ -28,7 +28,7 @@ bool GetShmemTempDir(FilePath* path) {
 #ifdef ANDROID
   return GetTempDir(path);
 #else
-  *path = FilePath("/dev/shm");
+  *path = FilePath("/tmp");
   return true;
 #endif
 }
