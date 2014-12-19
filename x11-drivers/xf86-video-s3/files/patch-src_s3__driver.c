--- src/s3_driver.c.orig	2012-07-17 04:50:05 UTC
+++ src/s3_driver.c
@@ -52,7 +52,6 @@
 #include "compiler.h"
 #include "mipointer.h"
 #include "micmap.h"
-#include "mibstore.h"
 #include "fb.h"
 #include "inputstr.h"
 #include "shadowfb.h"
@@ -822,7 +821,6 @@ static Bool S3ScreenInit(SCREEN_INIT_ARG
 	fbPictureInit (pScreen, 0, 0);
 	S3DGAInit(pScreen);
 
-        miInitializeBackingStore(pScreen);
         xf86SetBackingStore(pScreen);
 
 	/* framebuffer manager setup */
