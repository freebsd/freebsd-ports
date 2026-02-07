--- mmc.h.orig	2023-02-09 14:16:51 UTC
+++ mmc.h
@@ -17,8 +17,22 @@
  * those modifications are Copyright (c) 2016 SanDisk Corp.
  */
 
+#if defined(__linux__)
 #include <linux/major.h>
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
 
 /* From kernel linux/mmc/mmc.h */
 #define MMC_GO_IDLE_STATE         0   /* bc                          */
