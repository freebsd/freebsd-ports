--- src/parkverbot.c.orig	2013-01-28 15:01:56 UTC
+++ src/parkverbot.c
@@ -18,6 +18,7 @@
 #include <string.h>
 #include <time.h>
 #include <unistd.h>
+#include <sys/disk.h>
 #include <sys/mount.h>
 #include <libHX/init.h>
 #include <libHX/list.h>
@@ -34,7 +35,8 @@
 struct pv_bdev_entry {
 	struct HXlist_head anchor;
 	const char *path;
-	loff_t size, prev_pos;
+	off_t size, prev_pos;
+	unsigned sector_size;
 	int fd;
 };
 
@@ -43,7 +45,7 @@ static struct timespec pv_req_interval = {4, 0};
 static unsigned long long pv_disk_window = 16384;
 static unsigned long long pv_buffer_size = 64;
 
-static const char *pv_readable_size(char *buf, size_t bufsize, loff_t size)
+static const char *pv_readable_size(char *buf, size_t bufsize, off_t size)
 {
 	static const char unit_names[][2] =
 		{"", "K", "M", "G", "T", "P", "E", "Y", "Z"};
@@ -73,7 +75,7 @@ static bool pv_in_window(size_t prev_pos, size_t new_p
 static int pv_mainloop(void)
 {
 	struct pv_bdev_entry *e;
-	loff_t new_pos;
+	off_t new_pos;
 	ssize_t read_ret;
 	char *buffer;
 
@@ -86,6 +88,12 @@ static int pv_mainloop(void)
 	while (true) {
 		HXlist_for_each_entry(e, &pv_bdev_list, anchor) {
 			new_pos = HX_drand(0, e->size);
+			/*
+			 * read(2) and write(2) require the offset to be
+			 * a multiple of the sector size, otherwise they
+			 * will return EINVAL; see FreeBSD PR 91149.
+			 */
+			new_pos -= new_pos % e->sector_size;
 			if (pv_in_window(e->prev_pos, new_pos, e)) {
 				printf("%s: %llu (in guard window)\n", e->path,
 				       static_cast(unsigned long long, new_pos));
@@ -118,6 +126,7 @@ static bool pv_open_device(const char *path)
 	struct pv_bdev_entry *e;
 	char buf[32];
 	uint64_t size;
+	unsigned sector_size;
 	int fd;
 
 	fd = open(path, O_RDONLY | O_BINARY);
@@ -125,10 +134,14 @@ static bool pv_open_device(const char *path)
 		fprintf(stderr, "%s: %s\n", path, strerror(errno));
 		return false;
 	}
-	if (ioctl(fd, BLKGETSIZE64, &size) < 0) {
-		fprintf(stderr, "%s: BLKGETSIZE64: %s\n", path, strerror(errno));
+	if (ioctl(fd, DIOCGSECTORSIZE, &sector_size) < 0) {
+		fprintf(stderr, "%s: DIOCGSECTORSIZE: %s\n", path, strerror(errno));
 		return false;
 	}
+	if (ioctl(fd, DIOCGMEDIASIZE, &size) < 0) {
+		fprintf(stderr, "%s: DIOCGMEDIASIZE: %s\n", path, strerror(errno));
+		return false;
+	}
 	e = malloc(sizeof(*e));
 	if (e == NULL) {
 		fprintf(stderr, "%s: %s\n", __func__, strerror(errno));
@@ -138,9 +151,10 @@ static bool pv_open_device(const char *path)
 	HXlist_init(&e->anchor);
 	e->path = path;
 	e->size = size;
+	e->sector_size = sector_size;
 	e->fd   = fd;
-	printf("Added %s (size %s)\n", e->path,
-	       pv_readable_size(buf, sizeof(buf), e->size));
+	printf("Added %s (size %s, sector size %d bytes)\n", e->path,
+	       pv_readable_size(buf, sizeof(buf), e->size), sector_size);
 	HXlist_add_tail(&pv_bdev_list, &e->anchor);
 	return true;
 }
