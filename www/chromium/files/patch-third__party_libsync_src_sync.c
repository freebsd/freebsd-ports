--- third_party/libsync/src/sync.c.orig	2023-01-11 09:17:16 UTC
+++ third_party/libsync/src/sync.c
@@ -17,7 +17,11 @@
  */
 
 #include <fcntl.h>
+#if defined(__OpenBSD__)
+#include <stdlib.h>
+#else
 #include <malloc.h>
+#endif
 #include <stdint.h>
 #include <string.h>
 #include <errno.h>
@@ -29,6 +33,12 @@
 
 #include <sync/sync.h>
 
+#if defined(__OpenBSD__) || defined(__FreeBSD__)
+typedef __uint8_t __u8;
+typedef __uint32_t __u32;
+typedef __int32_t __s32;
+#define ETIME ETIMEDOUT
+#endif
 
 struct sw_sync_create_fence_data {
   __u32 value;
