--- mozilla/ipc/chromium/src/base/dir_reader_linux.h.orig	2011-12-16 21:29:22.000000000 +0100
+++ mozilla/ipc/chromium/src/base/dir_reader_linux.h	2011-12-19 21:00:27.000000000 +0100
@@ -9,6 +9,7 @@
 #include <errno.h>
 #include <fcntl.h>
 #include <stdint.h>
+#include <sys/dirent.h>
 #include <sys/syscall.h>
 #include <unistd.h>
 
@@ -19,6 +20,8 @@
 
 namespace base {
 
+#define linux_dirent struct dirent
+#if 0
 struct linux_dirent {
   uint64_t        d_ino;
   int64_t         d_off;
@@ -26,11 +29,16 @@
   unsigned char   d_type;
   char            d_name[0];
 };
+#endif
 
 class DirReaderLinux {
  public:
   explicit DirReaderLinux(const char* directory_path)
+#ifdef O_DIRECTORY
       : fd_(open(directory_path, O_RDONLY | O_DIRECTORY)),
+#else
+      : fd_(open(directory_path, O_RDONLY)),
+#endif
         offset_(0),
         size_(0) {
     memset(buf_, 0, sizeof(buf_));
@@ -57,7 +65,7 @@
     if (offset_ != size_)
       return true;
 
-    const int r = syscall(__NR_getdents64, fd_, buf_, sizeof(buf_));
+    const int r = syscall(SYS_getdents, fd_, buf_, sizeof(buf_));
     if (r == 0)
       return false;
     if (r == -1) {
