--- src/mediawidget.cpp.orig	2010-02-06 19:05:37.000000000 +0100
+++ src/mediawidget.cpp	2010-02-06 19:06:10.000000000 +0100
@@ -18,6 +18,9 @@
  * 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
  */
 
+#include <sys/types.h>
+#include <sys/stat.h>
+
 #include "mediawidget.h"
 #include "mediawidget_p.h"
 
