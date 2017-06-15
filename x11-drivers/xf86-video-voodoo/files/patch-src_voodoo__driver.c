# Remove obsolete function call
#
--- src/voodoo_driver.c.orig	2016-11-25 18:37:43 UTC
+++ src/voodoo_driver.c
@@ -680,7 +680,6 @@ VoodooScreenInit(SCREEN_INIT_ARGS_DECL)
   if(pVoo->Accel)
   	Voodoo2XAAInit(pScreen);
 
-  miInitializeBackingStore(pScreen);
   xf86SetBackingStore(pScreen);
   
 
