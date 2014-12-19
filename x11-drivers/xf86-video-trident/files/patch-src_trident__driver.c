--- src/trident_driver.c.orig	2012-07-16 02:16:00 UTC
+++ src/trident_driver.c
@@ -56,7 +56,6 @@
 
 #include "mipointer.h"
 
-#include "mibstore.h"
 #include "shadow.h"
 #include "trident.h"
 #include "trident_regs.h"
@@ -3037,7 +3036,6 @@ TRIDENTScreenInit(SCREEN_INIT_ARGS_DECL)
     	TridentAccelInit(pScreen);
     }
 
-    miInitializeBackingStore(pScreen);
     xf86SetBackingStore(pScreen);
 
     /* Initialise cursor functions */
