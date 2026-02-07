--- X11/button.h.orig	Sun Nov 11 20:24:37 2001
+++ X11/button.h	Sun Feb  9 15:05:21 2003
@@ -52,7 +52,7 @@
 #define WIDGET_BUTTON_H
 
 #include "param.h"
-#include "xpm.h"
+#include <X11/xpm.h>
 extern int make_pixmap_from_data (Widget parent, char **bits, Pixmap * bm);
 
 extern Widget
