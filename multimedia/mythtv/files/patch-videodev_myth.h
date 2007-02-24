--- ./libs/libmythtv/videodev_myth.h.orig	Wed Jan 31 22:16:51 2007
+++ ./libs/libmythtv/videodev_myth.h	Wed Jan 31 22:28:06 2007
@@ -5,12 +5,12 @@
 
 #if defined(__FreeBSD__) || defined(CONFIG_DARWIN)
 #include <sys/types.h>
-typedef unsigned long __u32;
-typedef unsigned short __u16;
-typedef int  __s32;
-typedef unsigned char __u8;
-typedef unsigned long long __u64;
-typedef long long __s64;
+typedef uint32_t __u32;
+typedef uint16_t __u16;
+typedef int32_t  __s32;
+typedef uint8_t __u8;
+typedef uint32_t __u64;
+typedef int32_t __s64;
 #else
 #include <linux/types.h>
 #include <linux/version.h>
