--- programs/Xserver/hw/xfree86/drivers/i810/i830_video.c.orig	Fri Dec 31 13:43:36 2004
+++ programs/Xserver/hw/xfree86/drivers/i810/i830_video.c	Fri Dec 31 13:44:22 2004
@@ -632,7 +632,7 @@
    pPriv->gamma0 = 0x080808;
 
    /* gotta uninit this someplace */
-   REGION_INIT(pScreen, &pPriv->clip, NullBox, 0);
+   REGION_NULL(pScreen, &pPriv->clip);
 
    pI830->adaptor = adapt;
 
