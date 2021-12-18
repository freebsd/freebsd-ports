--- mmc.h.orig	2021-12-18 19:59:21 UTC
+++ mmc.h
@@ -17,10 +17,26 @@
  * those modifications are Copyright (c) 2016 SanDisk Corp.
  */
 
+#if defined(__linux__)
 #include <linux/mmc/ioctl.h>
+#elif defined(__FreeBSD__)
+#include <dev/mmc/mmc_ioctl.h>
+#include <sys/endian.h>
+#include <sys/types.h>
+typedef int8_t   __s8;
+typedef uint8_t  __u8;
+typedef int16_t  __s16;
+typedef uint16_t __u16;
+typedef int32_t  __s32;
+typedef uint32_t __u32;
+typedef int64_t  __s64;
+typedef uint64_t __u64;
+#endif
 
+#if 0
 /* From kernel linux/major.h */
 #define MMC_BLOCK_MAJOR			179
+#endif
 
 /* From kernel linux/mmc/mmc.h */
 #define MMC_SWITCH		6	/* ac	[31:0] See below	R1b */
