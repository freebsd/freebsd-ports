--- programs/Xserver/hw/xfree86/os-support/linux/drm/xf86drmCompat.c.orig	Tue Aug 24 17:38:16 2004
+++ programs/Xserver/hw/xfree86/os-support/linux/drm/xf86drmCompat.c	Tue Aug 24 17:39:32 2004
@@ -77,8 +77,8 @@
 #include "mga_drm.h"
 #include "r128_drm.h"
 #include "radeon_drm.h"
-#ifndef __FreeBSD__
 #include "sis_drm.h"
+#ifndef __FreeBSD__
 #include "i810_drm.h"
 #include "i830_drm.h"
 #endif
@@ -1012,7 +1012,6 @@
    }
 }
 
-#ifndef __FreeBSD__
 /* SiS */
 
 Bool drmSiSAgpInit(int driSubFD, int offset, int size)
@@ -1026,6 +1025,7 @@
    return 1; /* TRUE */
 }
 
+#ifndef __FreeBSD__
 /* I830 */
 
 Bool drmI830CleanupDma(int driSubFD)
