--- base/files/dir_reader_linux.h.orig	2022-06-18 05:49:12 UTC
+++ base/files/dir_reader_linux.h
@@ -16,10 +16,16 @@
 #include "base/logging.h"
 #include "base/posix/eintr_wrapper.h"
 
+#include "build/build_config.h"
+
 // See the comments in dir_reader_posix.h about this.
 
 namespace base {
 
+#if BUILDFLAG(IS_BSD)
+#include <dirent.h>
+typedef struct dirent linux_dirent;
+#else
 struct linux_dirent {
   uint64_t        d_ino;
   int64_t         d_off;
@@ -27,6 +33,7 @@ struct linux_dirent {
   unsigned char   d_type;
   char            d_name[0];
 };
+#endif
 
 class DirReaderLinux {
  public:
@@ -61,7 +68,11 @@ class DirReaderLinux {
     if (offset_ != size_)
       return true;
 
+#if BUILDFLAG(IS_BSD)
+    const int r = getdents(fd_, reinterpret_cast<char *>(buf_), sizeof(buf_));
+#else
     const int r = syscall(__NR_getdents64, fd_, buf_, sizeof(buf_));
+#endif
     if (r == 0)
       return false;
     if (r == -1) {
