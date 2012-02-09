--- libexfat/io.c.orig	2012-01-14 10:24:11.000000000 +0100
+++ libexfat/io.c	2012-02-05 11:37:13.872786157 +0100
@@ -23,9 +23,29 @@
 #include <sys/types.h>
 #include <sys/uio.h>
 #include <sys/stat.h>
+#include <string.h>
 #include <fcntl.h>
 #define __USE_UNIX98 /* for pread() in Linux */
 #include <unistd.h>
+#ifdef __FreeBSD__
+#ifdef USE_UBLIO
+#include <sys/uio.h>
+#include "ublio.h"
+#define UBLIO_DEFAULT_BLOCKSIZE	262144
+#define UBLIO_DEFAULT_ITEMS	64
+#define UBLIO_DEFAULT_GRACE	32
+#define UBLIO_DEFAULT_SYNC_IO	0
+#define UBLIO_USE_API		1;
+struct unix_filehandle {
+	int fd;
+	ublio_filehandle_t ublio_fh;
+};
+
+struct unix_filehandle *ufh;
+#endif
+#include <sys/disk.h>
+static long devbsize; // block size for the gived device
+#endif
 
 #if _FILE_OFFSET_BITS != 64
 	#error You should define _FILE_OFFSET_BITS=64
@@ -49,26 +69,219 @@
 		exfat_error("failed to fstat `%s'", spec);
 		return -1;
 	}
-	if (!S_ISBLK(stbuf.st_mode) && !S_ISREG(stbuf.st_mode))
+	if (!S_ISCHR(stbuf.st_mode) && !S_ISREG(stbuf.st_mode) && !S_ISBLK(stbuf.st_mode))
 	{
 		close(fd);
-		exfat_error("`%s' is neither a block device, nor a regular file",
+		exfat_error("`%s' is neither a special device, nor a regular file",
 				spec);
 		return -1;
 	}
+#ifdef __FreeBSD__
+	devbsize = 512;
+	if (S_ISCHR(stbuf.st_mode) && ioctl(fd, DIOCGSECTORSIZE, &devbsize) < 0) {
+		exfat_error("Failed to ioctl(DIOCGSECTORSIZE) '%s'", spec);
+		return -1;
+	}
+#if USE_UBLIO
+	ufh = malloc(sizeof(*ufh));
+	if (!ufh)
+		return -1;
+
+	struct ublio_param up;
+	ufh->ublio_fh = NULL;
+	ufh->fd = fd;
+
+	up.up_blocksize = UBLIO_DEFAULT_BLOCKSIZE;
+	up.up_items = UBLIO_DEFAULT_ITEMS;
+	up.up_grace = UBLIO_DEFAULT_GRACE;
+	up.up_sync_io = UBLIO_DEFAULT_SYNC_IO;
+	up.up_priv	= &ufh->fd;
+	up.up_pread	= NULL;
+	up.up_preadv	= NULL;
+	up.up_pwrite	= NULL;
+	up.up_pwritev	= NULL; 
+	ufh->ublio_fh = ublio_open(&up);
+	if (!ufh->ublio_fh) {
+		close(fd);
+		exfat_error("ublio_open failed for %s", spec);
+		return -1;
+	}
+#endif
+
+#endif
 	return fd;
 }
 
+#define RAW_IO_MAX_SIZE (128 * 1024 * 1024)
+// #define DEVBSIZE 4096 // better get from the device, but 512 should work as well
+
+#define RAW_IO_ALIGNED(offset, count)			\
+	(devbsize == 0 ||			\
+	 ((offset) % devbsize == 0 &&	\
+	  (count) % devbsize == 0))
+#define RAW_IO_ALIGN(offset)				\
+	((offset) / devbsize * devbsize)
+#define RAW_IO_MAX_SIZE (128 * 1024 * 1024)
+
+#ifndef USE_UBLIO
+static int64_t aligned_pread(int fd, void *buf, int64_t count, int64_t offset)
+{
+	int64_t start, start_aligned;
+	int64_t end, end_aligned;
+	size_t count_aligned;
+	char *buf_aligned;
+	ssize_t nr;
+
+	/* short-circuit for regular files */
+	start = offset;
+	if (count > RAW_IO_MAX_SIZE)
+		count = RAW_IO_MAX_SIZE;
+	if (RAW_IO_ALIGNED(start, count))
+		return pread(fd, buf, count, start); 
+
+	/*
+	 * +- start_aligned                 +- end_aligned
+	 * |                                |
+	 * |     +- start           +- end  |
+	 * v     v                  v       v
+	 * |----------|----------|----------|
+	 *       ^                  ^
+	 *       +----- count ------+
+	 * ^                                ^
+	 * +-------- count_aligned ---------+
+	 */
+	start_aligned = RAW_IO_ALIGN(start);
+	end = start + count;
+	end_aligned = RAW_IO_ALIGN(end) +
+	    (RAW_IO_ALIGNED(end, 0) ? 0 : devbsize);
+	count_aligned = end_aligned - start_aligned;
+/*	exfat_debug(
+	    "%s: count = 0x%llx/0x%x, start = 0x%llx/0x%llx, end = 0x%llx/0x%llx\n",
+	    dev->d_name, count, count_aligned,
+	    start, start_aligned, end, end_aligned);
+*/
+	/* allocate buffer */
+	buf_aligned = malloc(count_aligned);
+	if (buf_aligned == NULL) {
+		exfat_debug("malloc(%zu) failed\n", count_aligned);
+		return -1;
+	}
+
+	/* read aligned data */
+	nr = pread(fd, buf_aligned, count_aligned, start_aligned);
+	if (nr == 0)
+		return 0;
+	if (nr < 0 || nr < start - start_aligned) {
+		free(buf_aligned);
+		return -1;
+	}
+
+	/* copy out */
+	memcpy(buf, buf_aligned + (start - start_aligned), count);
+	free(buf_aligned);
+
+	nr -= start - start_aligned;
+	if (nr > count)
+		nr = count;
+	return nr;
+}
+
+/**
+ * aligned_pwrite - Perform an aligned positioned write from the device
+ */
+static int64_t aligned_pwrite(int fd, void const *buf, size_t count, off_t offset)
+{
+	int64_t start, start_aligned;
+	int64_t end, end_aligned;
+	size_t count_aligned;
+	char *buf_aligned;
+	ssize_t nw;
+
+	/* short-circuit for regular files */
+	start = offset;
+	if (count > RAW_IO_MAX_SIZE)
+		count = RAW_IO_MAX_SIZE;
+	if (RAW_IO_ALIGNED(start, count))
+		return pwrite(fd, buf, count, start);
+
+	/*
+	 * +- start_aligned                 +- end_aligned
+	 * |                                |
+	 * |     +- start           +- end  |
+	 * v     v                  v       v
+	 * |----------|----------|----------|
+	 *       ^                  ^
+	 *       +----- count ------+
+	 * ^                                ^
+	 * +-------- count_aligned ---------+
+	 */
+	start_aligned = RAW_IO_ALIGN(start);
+	end = start + count;
+	end_aligned = RAW_IO_ALIGN(end) +
+	    (RAW_IO_ALIGNED(end, 0) ? 0 : devbsize);
+	count_aligned = end_aligned - start_aligned;
+	/* exfat_debug(
+	    "device:%d: count = 0x%llx/0x%x, start = 0x%llx/0x%llx, end = 0x%llx/0x%llx\n",
+	    fd, count, count_aligned,
+	    start, start_aligned, end, end_aligned); */
+
+	/* allocate buffer */
+	buf_aligned = malloc(count_aligned);
+	if (buf_aligned == NULL) {
+		exfat_error("malloc(%d) failed\n", count_aligned);
+		return -1;
+	}
+
+	/* read aligned lead-in */
+	if (pread(fd, buf_aligned, devbsize, start_aligned) != devbsize) {
+		exfat_debug("read lead-in failed\n");
+		free(buf_aligned);
+		return -1;
+	}
+
+	/* read aligned lead-out */
+	if (end != end_aligned && count_aligned > devbsize) {
+		if (pread(fd, buf_aligned + count_aligned - devbsize, devbsize, end_aligned - devbsize) != devbsize) {
+			exfat_error("read lead-out failed\n");
+			free(buf_aligned);
+			return -1;
+		}
+	}
+
+	/* copy data to write */
+	memcpy(buf_aligned + (start - start_aligned), buf, count);
+
+	/* write aligned data */
+	nw = pwrite(fd, buf_aligned, count_aligned, start_aligned);
+	free(buf_aligned);
+	if (nw < 0 || nw < start - start_aligned)
+		return -1;
+
+	nw -= start - start_aligned;
+	if (nw > count)
+		nw = count;
+	return nw;
+}
+#endif
+
 void exfat_read_raw(void* buffer, size_t size, off_t offset, int fd)
 {
-	if (pread(fd, buffer, size, offset) != size)
+#ifdef USE_UBLIO
+	if (ublio_pread(ufh->ublio_fh, buffer, size, offset) != size)
+#else
+	if (aligned_pread(fd, buffer, size, offset) != size)
+#endif
 		exfat_bug("failed to read %zu bytes from file at %"PRIu64, size,
 				(uint64_t) offset);
 }
 
 void exfat_write_raw(const void* buffer, size_t size, off_t offset, int fd)
 {
-	if (pwrite(fd, buffer, size, offset) != size)
+#ifdef USE_UBLIO
+	if (ublio_pwrite(ufh->ublio_fh, buffer, size, offset) != size)
+#else
+	if (aligned_pwrite(fd, buffer, size, offset) != size)
+#endif
 		exfat_bug("failed to write %zu bytes to file at %"PRIu64, size,
 				(uint64_t) offset);
 }
@@ -155,3 +368,14 @@
 	exfat_update_mtime(node);
 	return size - remainder;
 }
+
+int exfat_close(int fd) {
+#ifdef USE_UBLIO
+	ublio_fsync(ufh->ublio_fh);
+	ublio_close(ufh->ublio_fh);
+	
+#endif
+	if (close(fd) < 0)	/* close descriptor immediately after fsync */
+		return -1;
+	return 0;
+}
