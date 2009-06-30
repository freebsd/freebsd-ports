Index: bgpctl/bgpctl.c
===================================================================
RCS file: /home/cvs/private/hrs/openbgpd/bgpctl/bgpctl.c,v
retrieving revision 1.1.1.1
retrieving revision 1.2
diff -u -p -r1.1.1.1 -r1.2
--- bgpctl/bgpctl.c	30 Jun 2009 05:46:15 -0000	1.1.1.1
+++ bgpctl/bgpctl.c	30 Jun 2009 06:40:06 -0000	1.2
@@ -16,11 +16,19 @@
  * OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.
  */
 
+#if defined(__FreeBSD__)	/* compat */
+#include "openbsd-compat.h"
+#endif /* defined(__FreeBSD__) */
+
 #include <sys/types.h>
 #include <sys/socket.h>
 #include <sys/un.h>
 #include <net/if.h>
+#if defined(__FreeBSD__)	/* net/if_media.h */
+#include "if_media.h"
+#else
 #include <net/if_media.h>
+#endif /* defined(__FreeBSD__) */
 #include <net/if_types.h>
 
 #include <err.h>
@@ -29,7 +37,11 @@
 #include <stdlib.h>
 #include <string.h>
 #include <unistd.h>
+#if defined(__FreeBSD__)	/* util.h */
+#include "util.h"
+#else
 #include <util.h>
+#endif /* defined(__FreeBSD__) */
 
 #include "bgpd.h"
 #include "session.h"
@@ -38,6 +50,10 @@
 #include "parser.h"
 #include "irrfilter.h"
 
+#if defined(__FreeBSD__) /* FreeBSD has no LINK_STATE_IS_UP macro. */
+#define LINK_STATE_IS_UP(_s)  ((_s) >= LINK_STATE_UP)
+#endif /* defined(__FreeBSD__) */ 
+
 enum neighbor_views {
 	NV_DEFAULT,
 	NV_TIMERS
@@ -677,7 +693,7 @@ print_neighbor_msgstats(struct peer *p)
 }
 
 void
-print_timer(const char *name, timer_t d)
+print_timer(const char *name, time_t d)
 {
 	printf("  %-20s ", name);
 
