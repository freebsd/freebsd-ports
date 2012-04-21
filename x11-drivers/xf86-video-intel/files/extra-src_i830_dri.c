--- src/i830_dri.c.orig	2010-02-21 13:30:37.000000000 -0600
+++ src/i830_dri.c	2010-02-21 13:39:02.000000000 -0600
@@ -1731,9 +1731,10 @@
     info.driverName = IS_I965G(pI830) ? "i965" : "i915";
     info.deviceName = p;
     info.version = 1;
-
+#if 0
     info.CreateBuffers = I830DRI2CreateBuffers;
     info.DestroyBuffers = I830DRI2DestroyBuffers;
+#endif
     info.CopyRegion = I830DRI2CopyRegion;
 
     pI830->drmSubFD = info.fd;
