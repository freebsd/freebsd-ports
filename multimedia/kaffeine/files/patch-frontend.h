--- include/frontend.h.orig	2015-08-07 15:43:59 UTC
+++ include/frontend.h
@@ -26,7 +26,15 @@
 #ifndef _DVBFRONTEND_H_
 #define _DVBFRONTEND_H_
 
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
 
 typedef enum fe_type {
 	FE_QPSK,
