
$FreeBSD$

--- bgpd/rde_filter.c.orig
+++ bgpd/rde_filter.c
@@ -16,6 +16,7 @@
  * OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.
  */
 #include <sys/types.h>
+#include <sys/limits.h>
 #include <sys/queue.h>
 
 #include <stdlib.h>
