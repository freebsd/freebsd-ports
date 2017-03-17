--- mmc_cmds.c.orig	2017-01-25 19:03:34 UTC
+++ mmc_cmds.c
@@ -32,7 +32,11 @@
 #include <errno.h>
 #include <stdint.h>
 #include <assert.h>
+#if defined(__linux__)
 #include <linux/fs.h>
+#elif defined(__FreeBSD__)
+#include <sys/disk.h>
+#endif
 
 #include "mmc.h"
 #include "mmc_cmds.h"
@@ -120,8 +124,19 @@ static __u32 get_size_in_blks(int fd)
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
