--- protocols/icmp/nd_icmp.c.orig	Fri Sep 20 02:41:19 2002
+++ protocols/icmp/nd_icmp.c	Sun Oct 13 12:00:17 2002
@@ -22,6 +22,7 @@
 CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 
 */
+#include <sys/types.h>
 #include <sys/socket.h>
 #include <netinet/in.h>
 #include <arpa/inet.h>
