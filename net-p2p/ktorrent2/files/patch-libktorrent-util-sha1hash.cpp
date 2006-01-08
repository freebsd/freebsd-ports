--- libktorrent/util/sha1hash.cpp.orig	Sun Jan  8 02:28:06 2006
+++ libktorrent/util/sha1hash.cpp	Sun Jan  8 02:29:24 2006
@@ -17,6 +17,8 @@
  *   Free Software Foundation, Inc.,                                       *
  *   51 Franklin Steet, Fifth Floor, Boston, MA 02110-1301, USA.             *
  ***************************************************************************/
+#include <stdio.h>
+
 #include <qurl.h>
 #include <string.h>
 #include <algorithm>
