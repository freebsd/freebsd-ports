--- src/parkverbot.c.orig	2021-10-17 16:58:59 UTC
+++ src/parkverbot.c
@@ -18,6 +18,7 @@
 #include <string.h>
 #include <time.h>
 #include <unistd.h>
+#include <sys/disk.h>
 #include <sys/mount.h>
 #include <libHX/init.h>
 #include <libHX/list.h>
@@ -36,6 +37,7 @@ struct pv_bdev_entry {
 	struct HXlist_head anchor;
 	const char *path;
 	off_t size, prev_pos;
+	unsigned sector_size;
 	int fd;
 };
 
@@ -72,6 +74,12 @@ static int pv_mainloop(void)
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
@@ -104,6 +112,7 @@ static bool pv_open_device(const char *path)
 	struct pv_bdev_entry *e;
 	char buf[32];
 	uint64_t size;
+	unsigned sector_size;
 	int fd;
 
 	fd = open(path, O_RDONLY | O_BINARY);
@@ -111,10 +120,14 @@ static bool pv_open_device(const char *path)
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
@@ -124,9 +137,10 @@ static bool pv_open_device(const char *path)
 	HXlist_init(&e->anchor);
 	e->path = path;
 	e->size = size;
+	e->sector_size = sector_size;
 	e->fd   = fd;
-	printf("Added %s (size %s)\n", e->path,
-	       HX_unit_size(buf, sizeof(buf), e->size, 1024, 0));
+	printf("Added %s (size %s, sector size %d bytes)\n", e->path,
+	       HX_unit_size(buf, sizeof(buf), e->size, 1024, 0), sector_size);
 	HXlist_add_tail(&pv_bdev_list, &e->anchor);
 	return true;
 }
