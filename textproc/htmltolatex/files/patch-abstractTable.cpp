--- abstractTable.cpp.orig	Wed Oct 10 05:24:26 2001
+++ abstractTable.cpp	Sat Aug 16 16:13:04 2003
@@ -18,15 +18,16 @@
  * Boston, MA 02111-1307, USA.
  *
  */
+
+using namespace std;
+
 #include "abstractTable.h"
 #include "safe_ostrstream.h"
 #include "util.h"
+#include <cassert>
 #include <stdio.h>
 
 //#define DEBUG 1
-
-using namespace std;
-
 
 ostream& operator<<(ostream &o,const tabCell &c)
 {
