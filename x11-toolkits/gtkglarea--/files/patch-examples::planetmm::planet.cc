
$FreeBSD$

--- examples/planetmm/planet.cc.orig
+++ examples/planetmm/planet.cc
@@ -16,7 +16,7 @@
   Software Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
 
 *********************************************************************/
-#include <iostream.h>
+#include <iostream>
 #include <GL/glx.h>
 #include <glib.h>
 #include <gdk/gdk.h>
@@ -28,6 +28,8 @@
 #include <math.h>
 #include "globeGL.hh"
 
+using namespace std;
+
 // WARNING: Verbosity level set to maximum, prepare to get an ear full
 
 /*********************************************************************
@@ -468,7 +470,7 @@
 ************************************************************
   very simple main body
 ***********************************************************/
-gint main(gint argc, gchar **argv)
+int main(gint argc, gchar **argv)
   {
    MainWindowClass *main_window1;
   
