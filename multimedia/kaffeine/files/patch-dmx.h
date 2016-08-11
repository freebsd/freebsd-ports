--- include/dmx.h.orig	2015-08-07 15:43:59 UTC
+++ include/dmx.h
@@ -24,7 +24,16 @@
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
+typedef int64_t __s64;
+#endif
+
 #include <time.h>
 
 
