--- bgpctl/bgpctl.c.orig	Fri Aug 20 17:49:35 2004
+++ bgpctl/bgpctl.c	Sun Mar 20 15:27:10 2005
@@ -20,7 +20,6 @@
 #include <sys/socket.h>
 #include <sys/un.h>
 #include <net/if.h>
-#include <net/if_media.h>
 #include <net/if_types.h>
 
 #include <err.h>
@@ -35,6 +34,7 @@
 #include "rde.h"
 #include "log.h"
 #include "parser.h"
+#include "if_media.h"
 
 enum neighbor_views {
 	NV_DEFAULT,
