--- examples/pickmm/pick.cc.orig	Thu Jan 27 09:15:24 2000
+++ examples/pickmm/pick.cc	Fri Dec 20 09:42:57 2002
@@ -16,7 +16,7 @@
   Software Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
 
 *********************************************************************/
-#include <iostream.h>
+#include <iostream>
 
 #include <GL/gl.h>
 #include <GL/glu.h>
@@ -28,6 +28,8 @@
 #include <gtk--.h>
 
 #include <gtkgl--/glarea.h>
+
+using namespace std;
 
 // WARNING: Verbosity level set to maximum, prepare to get an ear full
 
