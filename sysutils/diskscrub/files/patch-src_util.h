--- src/util.h.orig	2013-01-09 15:24:03.000000000 -0500
+++ src/util.h	2013-01-09 15:24:22.000000000 -0500
@@ -24,6 +24,8 @@
  *  59 Temple Place, Suite 330, Boston, MA  02111-1307  USA.
 \*****************************************************************************/
 
+#include <sys/mman.h>
+
 #ifdef HAVE_STDBOOL_H
 #include <stdbool.h>
 #else
