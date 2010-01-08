--- uzbl-core.c.orig	2010-01-05 20:17:29.000000000 +0100
+++ uzbl-core.c	2010-01-08 10:13:45.000000000 +0100
@@ -29,6 +29,7 @@
  * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
  */
 
+#include <sys/errno.h>
 #include "uzbl-core.h"
 #include "callbacks.h"
 #include "events.h"
@@ -1436,7 +1437,7 @@
     sa.sun_family = AF_UNIX;
 
     /* create socket file descriptor and connect it to path */
-    fd = socket(AF_UNIX, SOCK_SEQPACKET, 0);
+    fd = socket(AF_UNIX, SOCK_STREAM, 0);
     if(fd == -1) {
         g_printerr("talk_to_socket: creating socket failed (%s)\n", strerror(errno));
         return;
