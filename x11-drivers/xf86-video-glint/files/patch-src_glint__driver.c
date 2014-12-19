--- src/glint_driver.c.orig	2012-07-16 02:50:47 UTC
+++ src/glint_driver.c
@@ -52,8 +52,6 @@
 #include "compiler.h"
 #include "mipointer.h"
 
-#include "mibstore.h"
-
 #include "pm3_regs.h"
 #include "glint_regs.h"
 #include "IBM.h"
@@ -2904,7 +2902,6 @@ GLINTScreenInit(SCREEN_INIT_ARGS_DECL)
         }
     }
 
-    miInitializeBackingStore(pScreen);
     xf86SetBackingStore(pScreen);
     xf86SetSilkenMouse(pScreen);
 
