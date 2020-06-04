--- lib/portability.c.orig	2020-05-11 18:23:26 UTC
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
@@ -522,6 +526,8 @@ int dev_minor(int dev)
   return ((dev&0xfff00000)>>12)|(dev&0xff);
 #elif defined(__APPLE__)
   return dev&0xffffff;
+#elif defined(__FreeBSD__)
+  return minor(dev);
 #else
 #error
 #endif
@@ -533,6 +539,8 @@ int dev_major(int dev)
   return (dev&0xfff00)>>8;
 #elif defined(__APPLE__)
   return (dev>>24)&0xff;
+#elif defined(__FreeBSD__)
+  return major(dev);
 #else
 #error
 #endif
@@ -544,6 +552,8 @@ int dev_makedev(int major, int minor)
   return (minor&0xff)|((major&0xfff)<<8)|((minor&0xfff00)<<12);
 #elif defined(__APPLE__)
   return (minor&0xffffff)|((major&0xff)<<24);
+#elif defined(__FreeBSD__)
+  return makedev(major, minor);
 #else
 #error
 #endif
@@ -593,5 +603,16 @@ int get_block_device_size(int fd, unsigned long long* 
 int get_block_device_size(int fd, unsigned long long* size)
 {
   return (ioctl(fd, BLKGETSIZE64, size) >= 0);
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
