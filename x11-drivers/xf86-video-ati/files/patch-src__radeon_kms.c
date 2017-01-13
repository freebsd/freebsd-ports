--- src/radeon_kms.c.orig	2015-11-12 03:57:33.000000000 +0100
+++ src/radeon_kms.c	2015-11-12 13:42:18.759377000 +0100
@@ -30,6 +30,8 @@
 
 #include <errno.h>
 #include <sys/ioctl.h>
+#include <sys/param.h>
+#include <sys/linker.h>
 /* Driver data structures */
 #include "radeon.h"
 #include "radeon_drm_queue.h"
@@ -829,7 +831,7 @@ static int radeon_get_drm_master_fd(Scrn
 #endif
     struct pci_device *dev = info->PciInfo;
     char *busid;
-    int fd;
+    int fd, err;
 
 #ifdef XF86_PDEV_SERVER_FD
     if (pRADEONEnt->platform_dev) {
@@ -848,6 +850,15 @@ static int radeon_get_drm_master_fd(Scrn
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
