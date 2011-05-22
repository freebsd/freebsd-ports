--- relayd.orig/log.c	2011-05-22 01:06:39.461146172 +0200
+++ relayd/log.c	2011-05-22 01:06:54.680052759 +0200
@@ -16,7 +16,11 @@
  * OUT OF OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.
  */
 
+#ifdef __FreeBSD__
+#include <sys/param.h>
+#else
 #include <sys/types.h>
+#endif
 #include <sys/queue.h>
 #include <sys/socket.h>
 #include <sys/tree.h>
