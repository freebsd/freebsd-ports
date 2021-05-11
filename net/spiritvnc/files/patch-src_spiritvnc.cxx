--- src/spiritvnc.cxx.orig	2021-02-15 06:05:31 UTC
+++ src/spiritvnc.cxx
@@ -46,6 +46,8 @@
 #include <FL/Fl_PNG_Image.H>
 #include "app.h"
 #include "consts_enums.h"
+#include <X11/xpm.h>
+#include "../spiritvnc.xpm"
 
 
 AppVars * app = new AppVars();
@@ -79,6 +81,12 @@ int main (int argc, char **argv)
 
     // set app icons
     svCreateAppIcons();
+
+    // set window's icon
+    Pixmap xpm, mask;
+    XpmCreatePixmapFromData(fl_display, DefaultRootWindow(fl_display),
+                            spiritvnc_xpm, &xpm, &mask, NULL);
+    app->mainWin->icon(reinterpret_cast<const void *>(xpm));
 
     // manually trigger misc events callback
     svPositionWidgets();
