--- examples/extra/events.cc.orig	Thu Jan 27 09:15:24 2000
+++ examples/extra/events.cc	Fri Dec 20 09:45:21 2002
@@ -18,7 +18,7 @@
 *********************************************************************/
 
 #include <string>
-#include <iostream.h>
+#include <iostream>
 #include <GL/glx.h>
 #include <glib.h>
 #include <gdk/gdk.h>
@@ -28,6 +28,7 @@
 #include <GL/gl.h>
 #include <GL/glu.h>
 
+using namespace std;
 
 void gl() {
   static int displaylist=-1;
