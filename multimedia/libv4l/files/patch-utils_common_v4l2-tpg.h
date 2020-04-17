--- utils/common/v4l2-tpg.h.orig	2020-04-09 16:29:54 UTC
+++ utils/common/v4l2-tpg.h
@@ -22,7 +22,9 @@ typedef int16_t s16;
 typedef uint8_t u8;
 typedef int8_t s8;
 
+#ifndef __packed
 #define __packed __attribute__((packed))
+#endif
 #define pr_info printf
 #define noinline
 
