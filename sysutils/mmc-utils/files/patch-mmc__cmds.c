--- mmc_cmds.c.orig	2023-08-07 11:14:42 UTC
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
@@ -95,8 +100,15 @@ int write_extcsd_value(int fd, __u8 index, __u8 value,
 
 	fill_switch_cmd(&idata, index, value);
 
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
@@ -128,8 +140,19 @@ static __u32 get_size_in_blks(int fd)
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
@@ -1981,8 +2004,10 @@ int do_read_extcsd(int nargs, char **argv)
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
@@ -2648,6 +2673,7 @@ int do_cache_dis(int nargs, char **argv)
 	return do_cache_ctrl(0, nargs, argv);
 }
 
+#if defined(__linux__)
 static int erase(int dev_fd, __u32 argin, __u32 start, __u32 end)
 {
 	int ret = 0;
@@ -2802,6 +2828,7 @@ out:
 	close(dev_fd);
 	return ret;
 }
+#endif
 
 static void set_ffu_single_cmd(struct mmc_ioc_multi_cmd *multi_cmd,
 			       __u8 *ext_csd, unsigned int bytes, __u8 *buf,
@@ -3137,6 +3164,7 @@ int do_preidle(int nargs, char **argv)
 	return 0;
 }
 
+#if defined(__linux__)
 int do_alt_boot_op(int nargs, char **argv)
 {
 	int fd, ret, boot_data_fd;
@@ -3239,3 +3267,4 @@ dev_fd_close:
 		exit(1);
 	return 0;
 }
+#endif
