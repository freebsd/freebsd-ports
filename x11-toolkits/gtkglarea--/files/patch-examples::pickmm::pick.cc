
$FreeBSD$

--- examples/pickmm/pick.cc.orig
+++ examples/pickmm/pick.cc
@@ -16,7 +16,7 @@
   Software Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
 
 *********************************************************************/
-#include <iostream.h>
+#include <iostream>
 
 #include <GL/gl.h>
 #include <GL/glu.h>
@@ -29,6 +29,8 @@
 
 #include <gtkgl--/glarea.h>
 
+using namespace std;
+
 // WARNING: Verbosity level set to maximum, prepare to get an ear full
 
 /*********************************************************************
@@ -596,7 +598,7 @@
 ************************************************************
   very simple main body
 ***********************************************************/
-gint main(gint argc, gchar **argv)
+int main(gint argc, gchar **argv)
   {
    MainWindowClass *main_window;
   
