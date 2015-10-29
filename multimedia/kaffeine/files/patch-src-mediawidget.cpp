--- src/mediawidget.cpp.orig	2015-08-07 15:43:59 UTC
+++ src/mediawidget.cpp
@@ -18,6 +18,9 @@
  * 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
  */
 
+#include <sys/types.h>
+#include <sys/stat.h>
+
 #include "mediawidget.h"
 #include "mediawidget_p.h"
 
