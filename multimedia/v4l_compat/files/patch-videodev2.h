--- videodev2.h.orig	2011-01-07 14:10:29.000000000 +0100
+++ videodev2.h	2011-01-07 14:11:23.000000000 +0100
@@ -62,16 +62,32 @@
 
 #ifndef HAVE_LINUX_INTEGER_TYPES
 /* XXX remove when depending software has been updated */
+#ifndef __u64
 typedef uint64_t __u64;
+#endif
+#ifndef __u32
 typedef uint32_t __u32;
+#endif
+#ifndef __u16
 typedef uint16_t __u16;
+#endif
+#ifndef __u8
 typedef uint8_t __u8;
+#endif
 
+#ifndef __s64
 typedef int64_t __s64;
+#endif
+#ifndef __s32
 typedef int32_t __s32;
+#endif
+#ifndef __s16
 typedef int16_t __s16;
+#endif
+#ifndef __s8
 typedef int8_t __s8;
 #endif
+#endif
 
 /*
  * Common stuff for both V4L1 and V4L2
