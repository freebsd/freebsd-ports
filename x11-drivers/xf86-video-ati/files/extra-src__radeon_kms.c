--- src/radeon_kms.c.orig	2013-08-07 10:44:09.000000000 +0200
+++ src/radeon_kms.c	2013-08-31 01:20:44.370468797 +0200
@@ -270,7 +270,7 @@
 radeon_dirty_update(ScreenPtr screen)
 {
 	RegionPtr region;
-	PixmapDirtyUpdatePtr ent;
+	PixmapDirtyUpdatePtr ent = NULL;
 
 	if (xorg_list_is_empty(&screen->pixmap_dirty_list))
 		return;
@@ -606,7 +606,7 @@
 		      dev->domain, dev->bus, dev->dev, dev->func);
 #endif
 
-    info->dri2.drm_fd = drmOpen("radeon", busid);
+    info->dri2.drm_fd = drmOpen("radeonkms", busid);
     if (info->dri2.drm_fd == -1) {
 
 	xf86DrvMsg(pScrn->scrnIndex, X_ERROR,
