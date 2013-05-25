--- src/mousePriv.h.orig	2012-07-27 08:10:56.000000000 +0200
+++ src/mousePriv.h	2012-07-30 00:39:00.000000000 +0200
@@ -63,8 +63,6 @@
     int         acc;
     CARD32      pnpLast;
     Bool        disablePnPauto;
-    float       fracdx,fracdy;
-    float       sensitivity;
 } mousePrivRec, *mousePrivPtr;
 
 /* mouse proto flags */
