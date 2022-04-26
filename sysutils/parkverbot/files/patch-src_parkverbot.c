--- src/parkverbot.c.orig	2022-04-10 12:51:33 UTC
+++ src/parkverbot.c
@@ -150,8 +150,8 @@ static bool pv_open_device(const char *path)
 	e->size = size;
 	e->sector_size = sector_size;
 	e->fd   = fd;
-	printf("Added %s (size %s)\n", e->path,
-	       HX_unit_size(buf, sizeof(buf), e->size, 1024, 0));
+	printf("Added %s (size %s, sector size %d bytes)\n", e->path,
+	       HX_unit_size(buf, sizeof(buf), e->size, 1024, 0), sector_size);
 	HXlist_add_tail(&pv_bdev_list, &e->anchor);
 	return true;
 }
