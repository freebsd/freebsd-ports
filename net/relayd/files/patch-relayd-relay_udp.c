--- relayd.orig/relay_udp.c	2011-05-22 01:06:39.460142978 +0200
+++ relayd/relay_udp.c	2011-05-22 01:06:54.703144104 +0200
@@ -16,7 +16,11 @@
  * OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.
  */
 
+#ifdef __FreeBSD__
+#include <sys/param.h>
+#else
 #include <sys/types.h>
+#endif
 #include <sys/queue.h>
 #include <sys/time.h>
 #include <sys/stat.h>
