--- src/radeon_kms.c.orig	2014-10-02 05:31:27.000000000 +0200
+++ src/radeon_kms.c	2014-10-23 18:56:18.359108170 +0200
@@ -30,6 +30,8 @@
 
 #include <errno.h>
 #include <sys/ioctl.h>
+#include <sys/param.h>
+#include <sys/linker.h>
 /* Driver data structures */
 #include "radeon.h"
 #include "radeon_reg.h"
@@ -280,7 +282,7 @@
 radeon_dirty_update(ScreenPtr screen)
 {
 	RegionPtr region;
-	PixmapDirtyUpdatePtr ent;
+	PixmapDirtyUpdatePtr ent = NULL;
 
 	if (xorg_list_is_empty(&screen->pixmap_dirty_list))
 		return;
@@ -589,7 +591,7 @@
 #endif
     struct pci_device *dev = info->PciInfo;
     char *busid;
-    int fd;
+    int fd, err;
 
 #ifdef XF86_PDEV_SERVER_FD
     if (pRADEONEnt->platform_dev) {
@@ -608,6 +610,15 @@
 		      dev->domain, dev->bus, dev->dev, dev->func);
 #endif
 
+    err = kldload("radeonkms");
+    if (err == -1 && errno != EEXIST) {
+	xf86DrvMsg(pScrn->scrnIndex, X_ERROR,
+		   "[drm] Failed to load kernel module for %s: %s\n",
+		   busid, strerror(errno));
+	free(busid);
+	return -1;
+    }
+
     fd = drmOpen(NULL, busid);
     if (fd == -1)
 	xf86DrvMsg(pScrn->scrnIndex, X_ERROR,
