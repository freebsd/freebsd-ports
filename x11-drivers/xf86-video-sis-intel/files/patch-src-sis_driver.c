--- src/sis_driver.c.orig	2007-05-02 05:13:00.000000000 +0400
+++ src/sis_driver.c	2008-05-27 03:31:36.000000000 +0400
@@ -559,9 +559,7 @@
 	    pScrn->FreeScreen       = SISFreeScreen;
 	    pScrn->ValidMode        = SISValidMode;
 #ifdef X_XF86MiscPassMessage
-	    if(xf86GetVersion() >= XF86_VERSION_NUMERIC(4,3,99,2,0)) {
 	       pScrn->HandleMessage = SISHandleMessage;
-	    }
 #endif
 	    foundScreen = TRUE;
 	}
