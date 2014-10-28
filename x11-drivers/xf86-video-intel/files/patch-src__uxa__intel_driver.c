--- src/uxa/intel_driver.c.orig	2014-10-28 00:30:09.015749289 +0100
+++ src/uxa/intel_driver.c	2014-10-28 00:30:26.834767496 +0100
@@ -723,7 +723,7 @@
 intel_dirty_update(ScreenPtr screen)
 {
 	RegionPtr region;
-	PixmapDirtyUpdatePtr ent;
+	PixmapDirtyUpdatePtr ent = NULL;
 
 	if (xorg_list_is_empty(&screen->pixmap_dirty_list))
 	    return;
