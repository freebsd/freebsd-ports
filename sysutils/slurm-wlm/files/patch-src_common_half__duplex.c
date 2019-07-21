--- src/common/half_duplex.c.orig	2019-06-09 17:09:36 UTC
+++ src/common/half_duplex.c
@@ -35,6 +35,11 @@
  *  51 Franklin Street, Fifth Floor, Boston, MA 02110-1301  USA.
 \*****************************************************************************/
 
+#ifdef __FreeBSD__
+#include <sys/types.h>
+#include <sys/socket.h>
+#endif
+
 #include "src/common/eio.h"
 #include "src/common/half_duplex.h"
 #include "src/common/list.h"
