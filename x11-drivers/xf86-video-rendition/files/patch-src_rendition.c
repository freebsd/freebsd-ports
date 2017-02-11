# Correct a string that should be const
#
--- src/rendition.c.orig	2014-09-30 14:21:44 UTC
+++ src/rendition.c
@@ -480,7 +480,7 @@ renditionPreInit(ScrnInfoPtr pScreenInfo
     MessageType       From;
     int               videoRam, Rounding, nModes = 0;
     renditionPtr      pRendition;
-    char             *in_string;
+    const char       *in_string;
     vgaHWPtr          pvgaHW;
     
 #ifdef DEBUG
