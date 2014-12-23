--- src/ark_driver.c.orig	2012-07-17 04:51:36 UTC
+++ src/ark_driver.c
@@ -39,7 +39,6 @@
 #include "compiler.h"
 #include "mipointer.h"
 #include "micmap.h"
-#include "mibstore.h"
 #include "fb.h"
 #include "ark.h"
 
@@ -538,7 +537,6 @@ static Bool ARKScreenInit(SCREEN_INIT_AR
 
 	fbPictureInit (pScreen, 0, 0);
 
-	miInitializeBackingStore(pScreen);
 	xf86SetBackingStore(pScreen);
 
 	if (!pARK->NoAccel) {
