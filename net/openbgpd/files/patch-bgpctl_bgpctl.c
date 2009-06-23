--- bgpctl/bgpctl.c.orig	2009-01-16 23:03:29.000000000 +0900
+++ bgpctl/bgpctl.c	2009-06-24 01:26:24.000000000 +0900
@@ -20,7 +20,6 @@
 #include <sys/socket.h>
 #include <sys/un.h>
 #include <net/if.h>
-#include <net/if_media.h>
 #include <net/if_types.h>
 
 #include <err.h>
@@ -29,14 +28,20 @@
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
+#include "compat-openbsd.h"
+
+#if defined(__FreeBSD__) /* FreeBSD has no LINK_STATE_IS_UP macro. */
+#define LINK_STATE_IS_UP(_s)  ((_s) >= LINK_STATE_UP)
+#endif /* defined(__FreeBSD__) */ 
 
 enum neighbor_views {
 	NV_DEFAULT,
@@ -84,7 +89,7 @@
 
 struct imsgbuf	*ibuf;
 
-__dead void
+ void
 usage(void)
 {
 	extern char	*__progname;
@@ -677,7 +682,7 @@
 }
 
 void
-print_timer(const char *name, timer_t d)
+print_timer(const char *name, time_t d)
 {
 	printf("  %-20s ", name);
 
