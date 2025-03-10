--- src/lib/clapper/features/server/clapper-server-mdns.c.orig	2025-01-21 21:12:03 UTC
+++ src/lib/clapper/features/server/clapper-server-mdns.c
@@ -16,7 +16,7 @@
  * Free Software Foundation, Inc., 51 Franklin St, Fifth Floor,
  * Boston, MA 02110-1301, USA.
  */
-
+#include <sys/socket.h>
 #include <gst/gst.h>
 
 #include "clapper-server-mdns-private.h"
