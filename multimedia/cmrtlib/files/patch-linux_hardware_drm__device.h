--- linux/hardware/drm_device.h.orig	2026-03-19 10:15:05 UTC
+++ linux/hardware/drm_device.h
@@ -39,7 +39,7 @@
 #include <limits.h>
 #include <signal.h>
 #include <time.h>
-#include <sys/sysmacros.h>   //<sys/types.h>
+#include <sys/types.h>
 #include <sys/stat.h>
 #define stat_t struct stat
 #include <sys/ioctl.h>
@@ -110,6 +110,10 @@
 #define DRM_NODE_CONTROL 1
 #define DRM_NODE_RENDER  2
 #define DRM_NODE_MAX     3
+
+#ifndef DRM_MAJOR
+#define DRM_MAJOR 226
+#endif
 
 typedef unsigned int  drmSize, *drmSizePtr;         /**< For mapped regions */
 typedef void          *drmAddress, **drmAddressPtr; /**< For mapped regions */
