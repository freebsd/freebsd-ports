--- relayd/check_icmp.c.orig	2008-01-14 10:10:32.881133017 +0900
+++ relayd/check_icmp.c	2008-01-14 10:10:45.169385174 +0900
@@ -16,7 +16,7 @@
  * OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.
  */
 
-#include <sys/types.h>
+#include <sys/param.h>
 #include <sys/queue.h>
 #include <sys/socket.h>
 
