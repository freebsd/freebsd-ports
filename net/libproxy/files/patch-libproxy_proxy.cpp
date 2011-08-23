--- libproxy/proxy.cpp.orig	2010-09-01 14:31:50.000000000 +0200
+++ libproxy/proxy.cpp	2010-09-01 14:32:09.000000000 +0200
@@ -17,6 +17,8 @@
  * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301 USA
  ******************************************************************************/
 
+#include <sys/types.h>
+
 #include <vector>
 #include <cstring>   // For strdup()
 #include <iostream>  // For cerr
