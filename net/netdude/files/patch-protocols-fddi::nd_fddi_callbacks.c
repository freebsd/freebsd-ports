--- protocols/fddi/nd_fddi_callbacks.c.orig	Wed Nov 20 21:37:07 2002
+++ protocols/fddi/nd_fddi_callbacks.c	Wed Nov 20 21:38:04 2002
@@ -22,7 +22,9 @@
 CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 
 */
+#include <sys/types.h>
 #include <netinet/if_fddi.h>
+#define FDDI_K_ALEN	6
 
 #include <netdude/nd_debug.h>
 #include <netdude/nd_macros.h>
