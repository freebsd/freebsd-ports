--- src/rendition.c.orig	2012-07-17 05:32:12 UTC
+++ src/rendition.c
@@ -1173,7 +1173,6 @@ renditionScreenInit(SCREEN_INIT_ARGS_DEC
     fbPictureInit (pScreen, 0, 0);
 
     xf86SetBlackWhitePixels(pScreen);
-    miInitializeBackingStore(pScreen);
    
     /*********************************************************/
     /* The actual setup of the driver-specific code          */
