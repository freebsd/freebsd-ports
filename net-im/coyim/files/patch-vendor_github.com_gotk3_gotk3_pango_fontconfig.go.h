Do proper type conversion for FreeBSD's fontconfig(3).

--- vendor/github.com/gotk3/gotk3/pango/fontconfig.go.h.orig	2019-04-14 03:24:49 UTC
+++ vendor/github.com/gotk3/gotk3/pango/fontconfig.go.h
@@ -2,6 +2,6 @@
 #include <fontconfig/fontconfig.h>
 
 static int addFont(char* font) {
-    FcBool fontAddStatus = FcConfigAppFontAddFile(FcConfigGetCurrent(), font);
+    FcBool fontAddStatus = FcConfigAppFontAddFile(FcConfigGetCurrent(), (unsigned char*)font);
     return fontAddStatus;
 }
