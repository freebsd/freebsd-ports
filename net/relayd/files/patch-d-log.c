--- relayd/log.c.orig	2008-01-14 09:59:27.825621568 +0900
+++ relayd/log.c	2008-01-14 09:59:36.888069516 +0900
@@ -16,7 +16,7 @@
  * OUT OF OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.
  */
 
-#include <sys/types.h>
+#include <sys/param.h>
 #include <sys/queue.h>
 #include <sys/socket.h>
 #include <sys/tree.h>
