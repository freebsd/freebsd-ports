--- bgpd/rde_update.c	2008-03-18 15:40:50.000000000 +0100
+++ bgpd/rde_update.c	2008-03-18 15:32:21.000000000 +0100
@@ -17,13 +17,15 @@
  */
 #include <sys/types.h>
 #include <sys/queue.h>
-#include <sys/hash.h>
 
 #include <stdlib.h>
 #include <string.h>
 
 #include "bgpd.h"
 #include "rde.h"
+#include "hash.h"
+
+#include <limits.h>
 
 in_addr_t	up_get_nexthop(struct rde_peer *, struct rde_aspath *);
 int		up_generate_mp_reach(struct rde_peer *, struct update_attr *,
