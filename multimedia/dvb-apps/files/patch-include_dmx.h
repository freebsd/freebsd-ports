--- include/dmx.h.orig	2014-03-21 19:26:36 UTC
+++ include/dmx.h
@@ -24,7 +24,15 @@
 #ifndef _DVBDMX_H_
 #define _DVBDMX_H_
 
-#include <asm/types.h>
+#ifdef __FreeBSD__
+#define __u8 uint8_t
+#define __u16 uint16_t
+#define __u32 uint32_t
+#define __u64 uint64_t
+#define __s16 int16_t
+#define __s32 int32_t
+#endif
+
 #ifdef __KERNEL__
 #include <linux/time.h>
 #else
