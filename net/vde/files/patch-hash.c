--- hash.c	Sat Jan 29 15:02:08 2005
+++ hash.c	Sat Jan 29 15:08:18 2005
@@ -14,7 +14,11 @@
 #include <syslog.h>
 #include <sys/types.h>
 #include <sys/time.h>
+#ifdef __FreeBSD__
+#include <signal.h>
+#else
 #include <sys/signal.h>
+#endif
 #include "switch.h"
 #include "hash.h"
 
@@ -129,7 +133,7 @@
   printf("Hash: %d Addr: %02x:%02x:%02x:%02x:%02x:%02x to port: %s  " 
 	 "age %ld secs\n", calc_hash(e->dst),
 	 e->dst[0], e->dst[1], e->dst[2], e->dst[3], e->dst[4], e->dst[5],
-	 (*p->port_id)(e->port), (int) p->now - e->last_seen);
+	 (*p->port_id)(e->port), (long) p->now - e->last_seen);
 }
 
 void print_hash(char *(*port_id)(void *))
