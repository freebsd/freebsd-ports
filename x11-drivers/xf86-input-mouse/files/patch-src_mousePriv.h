--- src/mousePriv.h.orig	2014-08-12 06:36:34 UTC
+++ src/mousePriv.h
@@ -63,8 +63,6 @@ typedef struct {
     int         acc;
     CARD32      pnpLast;
     Bool        disablePnPauto;
-    float       fracdx,fracdy;
-    float       sensitivity;
 } mousePrivRec, *mousePrivPtr;
 
 /* mouse proto flags */
