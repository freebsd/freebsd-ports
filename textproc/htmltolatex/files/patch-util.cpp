
$FreeBSD$

--- util.cpp.orig	Fri Feb 21 03:47:33 2003
+++ util.cpp	Fri Feb 21 03:47:46 2003
@@ -18,6 +18,9 @@
  * Boston, MA 02111-1307, USA.
  *
  */
+
+using namespace std;
+
 #include "util.h"
 #include <map>
 #include <ctype.h>
@@ -35,7 +38,6 @@
 #include "fetch.h"
 }
 #endif
-using namespace std;
 
 static map<string,int> gsSpecialTable;
 
