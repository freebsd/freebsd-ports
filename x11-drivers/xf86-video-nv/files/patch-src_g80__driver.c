--- src/g80_driver.c.orig	2012-07-17 06:47:02 UTC
+++ src/g80_driver.c
@@ -34,7 +34,6 @@
 #include <xf86Resources.h>
 #endif
 #include <mipointer.h>
-#include <mibstore.h>
 #include <micmap.h>
 #include <xf86cmap.h>
 #include <fb.h>
@@ -833,7 +832,6 @@ G80ScreenInit(SCREEN_INIT_ARGS_DECL)
         }
     }
 
-    miInitializeBackingStore(pScreen);
     xf86SetBackingStore(pScreen);
     xf86SetSilkenMouse(pScreen);
 
