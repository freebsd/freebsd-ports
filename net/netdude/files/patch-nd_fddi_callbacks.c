--- protocols/fddi/nd_fddi_callbacks.c.orig	Sat Oct 12 00:29:27 2002
+++ protocols/fddi/nd_fddi_callbacks.c	Sat Oct 12 00:33:10 2002
@@ -22,8 +22,6 @@
 CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 
 */
-#include <netinet/if_fddi.h>
-
 #include <netdude/nd_debug.h>
 #include <netdude/nd_macros.h>
 #include <netdude/nd_gui.h>
@@ -73,7 +71,7 @@
       if (!fh)
 	continue;
 
-      memcpy(fh->fddi_dhost, address, FDDI_K_ALEN);
+      memcpy(fh->fddi_dhost, address, FDDI_ADDR_LEN);
       nd_packet_modified_at_index(nd_pit_get(&pit), nd_pit_get_index(&pit));
     }
   
@@ -119,7 +117,7 @@
       if (!fh)
 	continue;
 
-      memcpy(fh->fddi_shost, address, FDDI_K_ALEN);
+      memcpy(fh->fddi_shost, address, FDDI_ADDR_LEN);
       nd_packet_modified_at_index(nd_pit_get(&pit), nd_pit_get_index(&pit));
     }
   
