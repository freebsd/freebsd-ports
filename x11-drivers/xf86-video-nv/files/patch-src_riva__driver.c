--- src/riva_driver.c.orig	2012-07-17 06:47:02 UTC
+++ src/riva_driver.c
@@ -1168,7 +1168,6 @@ RivaScreenInit(SCREEN_INIT_ARGS_DECL)
     if (!pRiva->NoAccel)
 	RivaAccelInit(pScreen);
     
-    miInitializeBackingStore(pScreen);
     xf86SetBackingStore(pScreen);
     xf86SetSilkenMouse(pScreen);
 
