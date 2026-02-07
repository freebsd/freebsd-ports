--- vmwgfx/vmwgfx_driver.h.orig	2021-12-02 13:55:36 UTC
+++ vmwgfx/vmwgfx_driver.h
@@ -40,6 +40,7 @@
 #include <xf86drm.h>
 #include <xf86drmMode.h>
 #include <xorg-server.h>
+#undef bool
 #include <xf86.h>
 #include <xf86Crtc.h>
 #include <xf86xv.h>
