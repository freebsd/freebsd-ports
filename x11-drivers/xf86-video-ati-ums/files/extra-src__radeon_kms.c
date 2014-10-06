--- src/radeon_kms.c.orig	2013-08-07 10:44:09.000000000 +0200
+++ src/radeon_kms.c	2013-08-31 19:29:11.369001510 +0200
@@ -30,6 +30,8 @@
 
 #include <errno.h>
 #include <sys/ioctl.h>
+#include <sys/param.h>
+#include <sys/linker.h>
 /* Driver data structures */
 #include "radeon.h"
 #include "radeon_reg.h"
@@ -270,7 +272,7 @@
 radeon_dirty_update(ScreenPtr screen)
 {
 	RegionPtr region;
-	PixmapDirtyUpdatePtr ent;
+	PixmapDirtyUpdatePtr ent = NULL;
 
 	if (xorg_list_is_empty(&screen->pixmap_dirty_list))
 		return;
@@ -606,6 +608,16 @@
 		      dev->domain, dev->bus, dev->dev, dev->func);
 #endif
 
+    err = kldload("radeonkms");
+    if (err == -1 && errno != EEXIST) {
+
+	xf86DrvMsg(pScrn->scrnIndex, X_ERROR,
+		   "[drm] Failed to load kernel module for %s: %s\n",
+		   busid, strerror(errno));
+	free(busid);
+	return FALSE;
+    }
+
     info->dri2.drm_fd = drmOpen("radeon", busid);
     if (info->dri2.drm_fd == -1) {
 
