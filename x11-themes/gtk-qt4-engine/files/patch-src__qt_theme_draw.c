--- ./src/qt_theme_draw.c.orig	2008-03-11 01:30:19.000000000 +0000
+++ ./src/qt_theme_draw.c	2013-03-28 12:45:32.271244758 +0000
@@ -19,11 +19,12 @@
  ***************************************************************************/
 
 #include <math.h>
+#include <stdlib.h>
 #include <string.h>
 #include <gtk/gtkprogressbar.h>
 #include <gdk/gdk.h>
 #include <gtk/gtk.h>
-#include <glib/glist.h>
+#include <glib.h>
 
 #ifdef HAVE_BONOBO
 #include <libbonobo.h>
