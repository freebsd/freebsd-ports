--- mmc_cmds.c.orig	2023-02-09 14:16:51 UTC
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
@@ -88,8 +93,15 @@ int write_extcsd_value(int fd, __u8 index, __u8 value,
 			(value << 8) |
 			EXT_CSD_CMD_SET_NORMAL;
 	idata.flags = MMC_RSP_SPI_R1B | MMC_RSP_R1B | MMC_CMD_AC;
+#if defined(__FreeBSD__)
+	if (timeout_ms != 0) {
+		fprintf(stderr, "Command timeout not supported\n");
+		return -EOPNOTSUPP;
+	}
+#else
 	/* Kernel will set cmd_timeout_ms if 0 is set */
 	idata.cmd_timeout_ms = timeout_ms;
+#endif
 
 	ret = ioctl(fd, MMC_IOC_CMD, &idata);
 	if (ret)
@@ -121,8 +133,19 @@ static __u32 get_size_in_blks(int fd)
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
@@ -1974,8 +1997,10 @@ int do_read_extcsd(int nargs, char **argv)
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
@@ -2646,6 +2671,7 @@ int do_cache_dis(int nargs, char **argv)
 	return do_cache_ctrl(0, nargs, argv);
 }
 
+#if defined(__linux__)
 static int erase(int dev_fd, __u32 argin, __u32 start, __u32 end)
 {
 	int ret = 0;
@@ -2800,6 +2826,7 @@ out:
 	close(dev_fd);
 	return ret;
 }
+#endif
 
 
 int do_ffu(int nargs, char **argv)
@@ -3145,6 +3172,7 @@ int do_preidle(int nargs, char **argv)
 	return 0;
 }
 
+#if defined(__linux__)
 int do_alt_boot_op(int nargs, char **argv)
 {
 	int fd, ret, boot_data_fd;
@@ -3247,3 +3275,4 @@ dev_fd_close:
 		exit(1);
 	return 0;
 }
+#endif
