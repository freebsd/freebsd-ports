--- format.C	Mon Jul 29 20:12:13 2002
+++ format.C	Thu Feb  5 22:47:07 2004
@@ -34,7 +34,7 @@
  /***************************************************************************/
 
 
-#include <strstream.h>
+#include <strstream>
 
 #include <stdlib.h>
 #include <ctype.h>
@@ -50,6 +50,7 @@
 
 using std::endl;
 using std::flush;
+using std::ostrstream;
 
 #ifndef nelems
 #define nelems(array) (sizeof(array) / sizeof((array)[0]))
