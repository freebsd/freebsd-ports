
$FreeBSD$

--- StyleTree.cpp.orig	Wed Oct 10 14:24:25 2001
+++ StyleTree.cpp	Fri Feb 21 22:10:03 2003
@@ -18,8 +18,12 @@
  * Boston, MA 02111-1307, USA.
  *
  */
+
+using namespace std;
+
 #include "StyleTree.h"
 #include <stdexcept>
+#include <ostream.h>
 
 void StyleTag::set_from_unparsed_string(const string &s)
 {
