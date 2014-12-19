--- src/radeon_driver.c.orig	2012-06-25 08:19:41 UTC
+++ src/radeon_driver.c
@@ -3756,7 +3756,6 @@ Bool RADEONScreenInit(SCREEN_INIT_ARGS_D
     /* Backing store setup */
     xf86DrvMsgVerb(pScrn->scrnIndex, X_INFO, RADEON_LOGLEVEL_DEBUG,
 		   "Initializing backing store\n");
-    miInitializeBackingStore(pScreen);
     xf86SetBackingStore(pScreen);
 
     /* DRI finalisation */
