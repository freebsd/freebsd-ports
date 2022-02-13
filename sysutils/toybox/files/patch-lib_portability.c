--- lib/portability.c.orig	2021-12-02 04:45:52 UTC
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
@@ -332,7 +336,7 @@ ssize_t xattr_fset(int fd, const char* name,
   return fsetxattr(fd, name, value, size, 0, flags);
 }
 
-#elif !defined(__OpenBSD__)
+#elif defined(__FreeBSD__) || defined(__OpenBSD__)
 
 ssize_t xattr_get(const char *path, const char *name, void *value, size_t size)
 {
@@ -537,6 +541,8 @@ int dev_minor(int dev)
   return dev&0xffffff;
 #elif defined(__OpenBSD__)
   return minor(dev);
+#elif defined(__FreeBSD__)
+  return minor(dev);
 #else
 #error
 #endif
@@ -550,6 +556,8 @@ int dev_major(int dev)
   return (dev>>24)&0xff;
 #elif defined(__OpenBSD__)
   return major(dev);
+#elif defined(__FreeBSD__)
+  return major(dev);
 #else
 #error
 #endif
@@ -563,6 +571,8 @@ int dev_makedev(int major, int minor)
   return (minor&0xffffff)|((major&0xff)<<24);
 #elif defined(__OpenBSD__)
   return makedev(major, minor);
+#elif defined(__FreeBSD__)
+  return makedev(major, minor);
 #else
 #error
 #endif
@@ -623,6 +633,17 @@ int get_block_device_size(int fd, unsigned long long* 
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
 
 // TODO copy_file_range
@@ -690,7 +711,7 @@ int timer_create_wrap(clockid_t c, struct sigevent *se
   };
   int timer;
 
-  if (syscall(SYS_timer_create, c, &kk, &timer)<0) return -1;
+  if (syscall(SYS_ktimer_create, c, &kk, &timer)<0) return -1;
   *t = (timer_t)(long)timer;
 
   return 0;
@@ -699,6 +720,6 @@ int timer_create_wrap(clockid_t c, struct sigevent *se
 int timer_settime_wrap(timer_t t, int flags, struct itimerspec *val,
   struct itimerspec *old)
 {
-  return syscall(SYS_timer_settime, t, flags, val, old);
+  return syscall(SYS_ktimer_settime, t, flags, val, old);
 }
 #endif
