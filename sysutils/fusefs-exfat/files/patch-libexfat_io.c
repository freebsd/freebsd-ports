--- libexfat/io.c	2012-01-25 13:07:21.467957180 +0000
+++ libexfat/io.c	2012-01-25 13:26:10.599952890 +0000
@@ -23,6 +23,7 @@
 #include <sys/types.h>
 #include <sys/uio.h>
 #include <sys/stat.h>
+#include <string.h>
 #include <fcntl.h>
 #define __USE_UNIX98 /* for pread() in Linux */
 #include <unistd.h>
@@ -49,26 +50,177 @@
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
 	return fd;
 }
 
+#define RAW_IO_MAX_SIZE (128 * 1024 * 1024)
+#define DEVBSIZE 512 // better get from the device, but 512 should work as well
+#define RAW_IO_ALIGNED(offset, count)			\
+	(DEVBSIZE == 0 ||			\
+	 ((offset) % DEVBSIZE == 0 &&	\
+	  (count) % DEVBSIZE == 0))
+#define RAW_IO_ALIGN(offset)				\
+	((offset) / DEVBSIZE * DEVBSIZE)
+#define RAW_IO_MAX_SIZE (128 * 1024 * 1024)
+
+
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
+	    (RAW_IO_ALIGNED(end, 0) ? 0 : DEVBSIZE);
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
+	    (RAW_IO_ALIGNED(end, 0) ? 0 : DEVBSIZE);
+	count_aligned = end_aligned - start_aligned;
+	exfat_debug(
+	    "device:%d: count = 0x%llx/0x%x, start = 0x%llx/0x%llx, end = 0x%llx/0x%llx\n",
+	    fd, count, count_aligned,
+	    start, start_aligned, end, end_aligned);
+
+	/* allocate buffer */
+	buf_aligned = malloc(count_aligned);
+	if (buf_aligned == NULL) {
+		exfat_error("malloc(%d) failed\n", count_aligned);
+		return -1;
+	}
+
+	/* read aligned lead-in */
+	if (pread(fd, buf_aligned, DEVBSIZE, start_aligned) != DEVBSIZE) {
+		exfat_debug("read lead-in failed\n");
+		free(buf_aligned);
+		return -1;
+	}
+
+	/* read aligned lead-out */
+	if (end != end_aligned && count_aligned > DEVBSIZE) {
+		if (pread(fd, buf_aligned + count_aligned - DEVBSIZE, DEVBSIZE, end_aligned - DEVBSIZE) != DEVBSIZE) {
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
+
+
 void exfat_read_raw(void* buffer, size_t size, off_t offset, int fd)
 {
-	if (pread(fd, buffer, size, offset) != size)
+	if (aligned_pread(fd, buffer, size, offset) != size)
 		exfat_bug("failed to read %zu bytes from file at %"PRIu64, size,
 				(uint64_t) offset);
 }
 
 void exfat_write_raw(const void* buffer, size_t size, off_t offset, int fd)
 {
-	if (pwrite(fd, buffer, size, offset) != size)
+	if (aligned_pwrite(fd, buffer, size, offset) != size)
 		exfat_bug("failed to write %zu bytes to file at %"PRIu64, size,
 				(uint64_t) offset);
 }
