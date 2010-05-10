--- plugins/vnc/vinagre-vnc-listener-dialog.c.orig	2010-01-06 19:49:40.000000000 -0500
+++ plugins/vnc/vinagre-vnc-listener-dialog.c	2010-01-06 19:49:55.000000000 -0500
@@ -18,6 +18,8 @@
  * along with this program. If not, see <http://www.gnu.org/licenses/>.
  */
 
+#include <sys/types.h>
+#include <sys/socket.h>
 #include <net/if.h>
 #include <arpa/inet.h>
 #include <netinet/in.h>
