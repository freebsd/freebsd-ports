--- examples/extra/glpixmap.cc.orig	Wed Aug 28 14:02:08 2002
+++ examples/extra/glpixmap.cc	Wed Aug 28 14:02:29 2002
@@ -27,6 +27,7 @@
 #include <gdk--.h>
 #include <gtkgl--/gdkgl.h>
 
+using namespace std;
 
 int visual_attributes[] = { GDK_GL_RGBA,
 			    GDK_GL_NONE };
