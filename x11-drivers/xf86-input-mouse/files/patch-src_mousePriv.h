--- src/mousePriv.h.orig	2012-05-28 00:01:45 UTC
+++ src/mousePriv.h
@@ -63,8 +63,6 @@ typedef struct {
     int         acc;
     CARD32      pnpLast;
     Bool        disablePnPauto;
-    float       fracdx,fracdy;
-    float       sensitivity;
 } mousePrivRec, *mousePrivPtr;
 
 /* mouse proto flags */
