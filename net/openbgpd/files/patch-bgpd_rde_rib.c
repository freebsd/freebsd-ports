--- bgpd/rde_rib.c	2008-03-18 15:39:58.000000000 +0100
+++ bgpd/rde_rib.c	2008-03-18 15:31:36.000000000 +0100
@@ -18,13 +18,13 @@
 
 #include <sys/types.h>
 #include <sys/queue.h>
-#include <sys/hash.h>
 
 #include <stdlib.h>
 #include <string.h>
 
 #include "bgpd.h"
 #include "rde.h"
+#include "hash.h"
 
 /*
  * BGP RIB -- Routing Information Base
