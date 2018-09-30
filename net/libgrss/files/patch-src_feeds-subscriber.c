--- src/feeds-subscriber.c.orig	2015-07-15 20:59:07 UTC
+++ src/feeds-subscriber.c
@@ -18,6 +18,10 @@
  * Boston, MA  02110-1301, USA.
  */
 
+#include <sys/types.h>
+#include <sys/socket.h>
+#include <netinet/in.h>
+
 #include "feeds-subscriber.h"
 #include "feeds-subscriber-handler.h"
 #include "feeds-pubsubhubbub-subscriber.h"
