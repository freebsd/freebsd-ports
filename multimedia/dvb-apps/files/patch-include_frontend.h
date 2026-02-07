--- include/frontend.h.orig	2014-03-21 19:26:36 UTC
+++ include/frontend.h
@@ -28,8 +28,14 @@
 #ifndef _DVBFRONTEND_H_
 #define _DVBFRONTEND_H_
 
-#include <asm/types.h>
-
+#ifdef __FreeBSD__
+#define __u8 uint8_t
+#define __u16 uint16_t
+#define __u32 uint32_t
+#define __u64 uint64_t
+#define __s16 int16_t
+#define __s32 int32_t
+#endif
 
 typedef enum fe_type {
 	FE_QPSK,
