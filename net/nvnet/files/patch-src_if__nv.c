
$FreeBSD$

--- src/if_nv.c.orig	Sat Jun 26 11:58:36 2004
+++ src/if_nv.c	Sat Jun 26 11:59:07 2004
@@ -72,6 +72,7 @@
 #include <sys/socket.h>
 #include <sys/sysctl.h>
 #include <sys/queue.h>
+#include <sys/module.h>
 
 #include <net/if.h>
 #include <net/if_arp.h>
