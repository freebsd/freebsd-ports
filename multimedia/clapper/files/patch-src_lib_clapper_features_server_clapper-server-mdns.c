--- src/lib/clapper/features/server/clapper-server-mdns.c.orig	2025-12-22 10:36:43 UTC
+++ src/lib/clapper/features/server/clapper-server-mdns.c
@@ -15,7 +15,7 @@
  * License along with this library; if not, see
  * <https://www.gnu.org/licenses/>.
  */
-
+#include <sys/socket.h>
 #include <gst/gst.h>
 
 #include "clapper-server-mdns-private.h"
