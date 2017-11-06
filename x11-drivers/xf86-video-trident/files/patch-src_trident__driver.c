# Correct a string that should be const
#
--- src/trident_driver.c.orig	2015-03-30 17:05:53 UTC
+++ src/trident_driver.c
@@ -1010,7 +1010,7 @@ TRIDENTPreInit(ScrnInfoPtr pScrn, int fl
     ClockRangePtr clockRanges;
     Bool ddcLoaded = FALSE;
     xf86MonPtr pMon = NULL;
-    char *s;
+    const char *s;
     Bool tmp_bool;
 
     /* Allocate the TRIDENTRec driverPrivate */
