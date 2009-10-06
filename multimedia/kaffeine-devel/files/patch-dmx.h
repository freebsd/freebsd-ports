--- include/dmx.h.orig	2009-10-06 18:35:56.000000000 +0200
+++ include/dmx.h	2009-10-06 18:36:31.000000000 +0200
@@ -24,7 +24,15 @@
 #ifndef _DVBDMX_H_
 #define _DVBDMX_H_
 
-#include <linux/types.h>
+#ifndef LINUX_TYPES_ADDED
+#define LINUX_TYPES_ADDED
+#include <sys/types.h>
+typedef uint64_t __u64;
+typedef uint32_t __u32;
+typedef uint16_t __u16;
+typedef uint8_t __u8;
+#endif
+
 #ifdef __KERNEL__
 #include <linux/time.h>
 #else
