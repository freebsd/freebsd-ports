--- mgp.h.orig	Fri Jun  6 16:18:25 2003
+++ mgp.h	Sun May 16 19:02:09 2004
@@ -62,6 +62,7 @@
 #include <X11/cursorfont.h>
 #include <X11/Xatom.h>
 #ifdef USE_XFT2
+#include <ft2build.h>
 #include <freetype/freetype.h>
 #include <fontconfig/fontconfig.h>
 #include <X11/Xft/Xft.h>
