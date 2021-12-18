--- mmc_cmds.c.orig	2021-12-18 19:59:21 UTC
+++ mmc_cmds.c
@@ -28,7 +28,12 @@
 #include <errno.h>
 #include <stdint.h>
 #include <assert.h>
+#if defined(__linux__)
 #include <linux/fs.h> /* for BLKGETSIZE */
+#elif defined(__FreeBSD__)
+#include <stddef.h> /* for offsetof() */
+#include <sys/disk.h> /* for DIOCG{MEDIA,SECTOR}SIZE */
+#endif
 
 #include "mmc.h"
 #include "mmc_cmds.h"
@@ -120,8 +125,19 @@ static __u32 get_size_in_blks(int fd)
 {
 	int res;
 	int size;
+#if defined(__FreeBSD__)
+	off_t mediasize;
+#endif
 
+#if defined(__linux__)
 	res = ioctl(fd, BLKGETSIZE, &size);
+#elif defined(__FreeBSD__)
+	res = ioctl(fd, DIOCGMEDIASIZE, &mediasize);
+	if (!res) {
+		res = ioctl(fd, DIOCGSECTORSIZE, &size);
+		size = mediasize / size;
+	}
+#endif
 	if (res) {
 		fprintf(stderr, "Error getting device size, errno: %d\n",
 			errno);
@@ -1605,13 +1621,18 @@ int do_read_extcsd(int nargs, char **argv)
 	/* A441/A43: reserved	[197] [195] [193] [190] [188]
 	 * [186] [184] [182] [180] [176] */
 
-	if (ext_csd_rev >= 6)
+	if (ext_csd_rev >= 6) {
 		printf("I/O Driver Strength [DRIVER_STRENGTH: 0x%02x]\n",
 			ext_csd[197]);
+		printf("Enhanced Strobe mode [STROBE_SUPPORT: 0x%02x]\n",
+			ext_csd[184]);
+	}
 
 	/* DEVICE_TYPE in A45, CARD_TYPE in A441 */
 	reg = ext_csd[196];
 	printf("Card Type [CARD_TYPE: 0x%02x]\n", reg);
+	if (reg & 0x80) printf(" HS400 Dual Data Rate eMMC @200MHz 1.2VI/O\n");
+	if (reg & 0x40) printf(" HS400 Dual Data Rate eMMC @200MHz 1.8VI/O\n");
 	if (reg & 0x20) printf(" HS200 Single Data Rate eMMC @200MHz 1.2VI/O\n");
 	if (reg & 0x10) printf(" HS200 Single Data Rate eMMC @200MHz 1.8VI/O\n");
 	if (reg & 0x08) printf(" HS Dual Data Rate eMMC @52MHz 1.2VI/O\n");
@@ -1881,8 +1902,10 @@ int do_read_extcsd(int nargs, char **argv)
 		       (ext_csd[EXT_CSD_CMDQ_DEPTH] & 0x1f) + 1);
 		printf("Command Enabled [CMDQ_MODE_EN]: 0x%02x\n",
 		       ext_csd[EXT_CSD_CMDQ_MODE_EN]);
+#if defined(__linux__)
 		printf("Note: CMDQ_MODE_EN may not indicate the runtime CMDQ ON or OFF.\n"
 		       "Please check sysfs node '/sys/devices/.../mmc_host/mmcX/mmcX:XXXX/cmdq_en'\n");
+#endif
 	}
 out_free:
 	return ret;
@@ -2515,6 +2538,7 @@ int do_cache_dis(int nargs, char **argv)
 	return do_cache_ctrl(0, nargs, argv);
 }
 
+#if defined(__linux__)
 static int erase(int dev_fd, __u32 argin, __u32 start, __u32 end)
 {
 	int ret = 0;
@@ -2657,6 +2681,7 @@ out:
 	close(dev_fd);
 	return ret;
 }
+#endif
 
 
 int do_ffu(int nargs, char **argv)
