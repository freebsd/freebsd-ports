--- lib/portability.c.orig	2021-05-19 08:34:26 UTC
+++ lib/portability.c
@@ -6,6 +6,10 @@
 
 #include "toys.h"
 
+#if defined(__FreeBSD__)
+#include <sys/types.h>
+#endif
+
 // We can't fork() on nommu systems, and vfork() requires an exec() or exit()
 // before resuming the parent (because they share a heap until then). And no,
 // we can't implement our own clone() call that does the equivalent of fork()
@@ -536,6 +540,8 @@ int dev_minor(int dev)
   return dev&0xffffff;
 #elif defined(__OpenBSD__)
   return minor(dev);
+#elif defined(__FreeBSD__)
+  return minor(dev);
 #else
 #error
 #endif
@@ -549,6 +555,8 @@ int dev_major(int dev)
   return (dev>>24)&0xff;
 #elif defined(__OpenBSD__)
   return major(dev);
+#elif defined(__FreeBSD__)
+  return major(dev);
 #else
 #error
 #endif
@@ -562,6 +570,8 @@ int dev_makedev(int major, int minor)
   return (minor&0xffffff)|((major&0xff)<<24);
 #elif defined(__OpenBSD__)
   return makedev(major, minor);
+#elif defined(__FreeBSD__)
+  return makedev(major, minor);
 #else
 #error
 #endif
@@ -621,6 +631,17 @@ int get_block_device_size(int fd, unsigned long long* 
   int status = (ioctl(fd, DIOCGDINFO, &lab) >= 0);
   *size = lab.d_secsize * lab.d_nsectors;
   return status;
+}
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
 }
 #endif
 
