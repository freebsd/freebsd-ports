--- mmc_cmds.c.orig	2018-12-26 19:54:04 UTC
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
@@ -1530,13 +1546,18 @@ int do_read_extcsd(int nargs, char **arg
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
@@ -1883,7 +1904,7 @@ static int do_rpmb_op(int fd,
 	u_int16_t rpmb_type;
 	struct mmc_ioc_multi_cmd *mioc;
 	struct mmc_ioc_cmd *ioc;
-	struct rpmb_frame frame_status = {0};
+	struct rpmb_frame frame_status = {{0}};
 
 	if (!frame_in || !frame_out || !out_cnt)
 		return -EINVAL;
