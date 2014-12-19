--- src/i128_driver.c.orig	2012-07-17 05:21:15 UTC
+++ src/i128_driver.c
@@ -50,8 +50,6 @@
 /* All drivers initialising the SW cursor need this */
 #include "mipointer.h"
 
-/* All drivers implementing backing store need this */
-#include "mibstore.h"
 #include "micmap.h"
 
 #include "xf86DDC.h"
@@ -1557,7 +1555,6 @@ I128ScreenInit(SCREEN_INIT_ARGS_DECL)
         return FALSE;
     }
     
-    miInitializeBackingStore(pScreen);
     xf86SetBackingStore(pScreen);
     xf86SetSilkenMouse(pScreen);
 
