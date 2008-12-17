--- bgpctl/bgpctl.c	2007-08-06 21:16:06.000000000 +0200
+++ bgpctl/bgpctl.c	2008-03-18 14:27:24.000000000 +0100
@@ -20,7 +20,6 @@
 #include <sys/socket.h>
 #include <sys/un.h>
 #include <net/if.h>
-#include <net/if_media.h>
 #include <net/if_types.h>
 
 #include <err.h>
@@ -29,14 +28,19 @@
 #include <stdlib.h>
 #include <string.h>
 #include <unistd.h>
-#include <util.h>
 
 #include "bgpd.h"
 #include "session.h"
 #include "rde.h"
 #include "log.h"
 #include "parser.h"
+#include "util.h"
 #include "irrfilter.h"
+#include "if_media.h"
+
+#if defined(__FreeBSD__) /* FreeBSD has no LINK_STATE_IS_UP macro. */
+#define LINK_STATE_IS_UP(_s)  ((_s) >= LINK_STATE_UP)
+#endif /* defined(__FreeBSD__) */ 
 
 enum neighbor_views {
 	NV_DEFAULT,
