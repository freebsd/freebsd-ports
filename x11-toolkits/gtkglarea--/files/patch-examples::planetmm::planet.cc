--- examples/planetmm/planet.cc.orig	Thu Jan 27 09:15:25 2000
+++ examples/planetmm/planet.cc	Fri Dec 20 09:43:57 2002
@@ -16,7 +16,7 @@
   Software Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
 
 *********************************************************************/
-#include <iostream.h>
+#include <iostream>
 #include <GL/glx.h>
 #include <glib.h>
 #include <gdk/gdk.h>
@@ -27,6 +27,8 @@
 #include <GL/gl.h>
 #include <math.h>
 #include "globeGL.hh"
+
+using namespace std;
 
 // WARNING: Verbosity level set to maximum, prepare to get an ear full
 
