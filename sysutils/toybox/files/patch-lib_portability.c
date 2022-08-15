--- lib/portability.c.orig	2022-08-13 14:55:14 UTC
+++ lib/portability.c
@@ -625,6 +625,17 @@ int get_block_device_size(int fd, unsigned long long* 
   *size = lab.d_secsize * lab.d_nsectors;
   return status;
 }
+#elif defined(__FreeBSD__)
+#include <sys/disk.h>
+int get_block_device_size(int fd, unsigned long long* size)
+{
+  off_t sz = 0;
+  if (ioctl(fd, DIOCGMEDIASIZE, &sz) >= 0) {
+    *size = sz;
+    return 1;
+  }
+  return 0;
+}
 #endif
 
 // Return bytes copied from in to out. If bytes <0 copy all of in to out.
