--- chem3d/gtkchem3dviewer.cc.orig	Thu Jun 12 23:03:04 2003
+++ chem3d/gtkchem3dviewer.cc	Fri Jun 27 18:21:44 2003
@@ -30,6 +30,7 @@
 #include <gtk/gtk.h>
 #include <GL/gl.h>
 #include <GL/glu.h>
+#include <locale.h>
 #ifdef HAVE_GTKGLAREA
 #	include <gtkgl/gtkglarea.h>
 #else
