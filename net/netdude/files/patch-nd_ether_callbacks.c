--- protocols/ether/nd_ether_callbacks.c.orig	Sat Oct 12 00:20:26 2002
+++ protocols/ether/nd_ether_callbacks.c	Sat Oct 12 00:23:48 2002
@@ -22,6 +22,7 @@
 CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 
 */
+#include <sys/types.h>
 #include <net/ethernet.h>
 #include <netdude/nd.h>
 #include <netdude/nd_debug.h>
@@ -54,7 +55,7 @@
       if (!eh)
 	continue;
 
-      memcpy(eh->ether_shost, address, ETH_ALEN);
+      memcpy(eh->ether_shost, address, ETHER_ADDR_LEN);
       nd_packet_modified_at_index(nd_pit_get(&pit), nd_pit_get_index(&pit));
     }
   
@@ -84,7 +85,7 @@
       if (!eh)
 	continue;
 
-      memcpy(eh->ether_dhost, address, ETH_ALEN);
+      memcpy(eh->ether_dhost, address, ETHER_ADDR_LEN);
       nd_packet_modified_at_index(nd_pit_get(&pit), nd_pit_get_index(&pit));
     }
   
