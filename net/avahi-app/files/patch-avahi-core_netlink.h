--- avahi-core/netlink.h.orig	2015-04-01 04:58:14 UTC
+++ avahi-core/netlink.h
@@ -19,13 +19,17 @@
   Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307
   USA.
 ***/
-
+#ifdef __linux__
 #include <sys/socket.h>
 #include <asm/types.h>
 #include <inttypes.h>
 
 #include <linux/netlink.h>
 #include <linux/rtnetlink.h>
+#else
+#include <netlink/netlink.h>
+#include <netlink/netlink_route.h>
+#endif
 
 #include <avahi-common/watch.h>
 
