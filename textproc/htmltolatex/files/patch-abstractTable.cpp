
$FreeBSD$

--- abstractTable.cpp.orig	Fri Feb 21 03:09:19 2003
+++ abstractTable.cpp	Fri Feb 21 03:09:34 2003
@@ -18,15 +18,15 @@
  * Boston, MA 02111-1307, USA.
  *
  */
+
+using namespace std;
+
 #include "abstractTable.h"
 #include "safe_ostrstream.h"
 #include "util.h"
 #include <stdio.h>
 
 //#define DEBUG 1
-
-using namespace std;
-
 
 ostream& operator<<(ostream &o,const tabCell &c)
 {
