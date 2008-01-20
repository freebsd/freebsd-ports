--- relayd/relay_udp.c.orig	2008-01-14 10:09:08.345280942 +0900
+++ relayd/relay_udp.c	2008-01-14 10:09:21.665469901 +0900
@@ -16,7 +16,7 @@
  * OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.
  */
 
-#include <sys/types.h>
+#include <sys/param.h>
 #include <sys/queue.h>
 #include <sys/time.h>
 #include <sys/stat.h>
