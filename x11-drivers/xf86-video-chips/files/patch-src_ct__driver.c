--- src/ct_driver.c.orig	2012-07-16 03:35:59 UTC
+++ src/ct_driver.c
@@ -96,9 +96,6 @@
 /* All drivers initialising the SW cursor need this */
 #include "mipointer.h"
 
-/* All drivers implementing backing store need this */
-#include "mibstore.h"
-
 /* All drivers using the mi banking wrapper need this */
 #ifdef HAVE_ISA
 #include "mibank.h"
@@ -4145,7 +4142,6 @@ CHIPSScreenInit(SCREEN_INIT_ARGS_DECL)
 	    pBankInfo = NULL;
 	    return FALSE;
 	}
-	miInitializeBackingStore(pScreen);
 	xf86SetBackingStore(pScreen);
 
 	/* Initialise cursor functions */
@@ -4296,7 +4292,6 @@ CHIPSScreenInit(SCREEN_INIT_ARGS_DECL)
 	    }
 	}
 	
-	miInitializeBackingStore(pScreen);
 	xf86SetBackingStore(pScreen);
 #ifdef ENABLE_SILKEN_MOUSE
 	xf86SetSilkenMouse(pScreen);
