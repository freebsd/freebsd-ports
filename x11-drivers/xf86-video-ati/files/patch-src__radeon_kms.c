--- src/radeon_kms.c.orig	2016-11-17 02:23:37 UTC
+++ src/radeon_kms.c
@@ -30,6 +30,8 @@
 
 #include <errno.h>
 #include <sys/ioctl.h>
+#include <sys/param.h>
+#include <sys/linker.h>
 /* Driver data structures */
 #include "radeon.h"
 #include "radeon_drm_queue.h"
@@ -1405,6 +1407,15 @@ static int radeon_get_drm_master_fd(Scrn
     XNFasprintf(&busid, "pci:%04x:%02x:%02x.%d",
                 dev->domain, dev->bus, dev->dev, dev->func);
 
+    fd = kldload("radeonkms");
+    if (fd == -1 && errno != EEXIST) {
+	xf86DrvMsg(pScrn->scrnIndex, X_ERROR,
+		   "[drm] Failed to load kernel module for %s: %s\n",
+		   busid, strerror(errno));
+	free(busid);
+	return fd;
+    }
+
     fd = drmOpen(NULL, busid);
     if (fd == -1)
 	xf86DrvMsg(pScrn->scrnIndex, X_ERROR,
