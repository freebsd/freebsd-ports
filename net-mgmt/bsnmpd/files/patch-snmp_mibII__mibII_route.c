--- snmp_mibII/mibII_route.c.orig	Fri Oct  7 14:23:49 2005
+++ snmp_mibII/mibII_route.c	Fri Oct  7 14:24:05 2005
@@ -30,7 +30,7 @@
  *
  * Routing table
  */
-#include <sys/tree.h>
+#include "tree.h"
 #include "mibII.h"
 #include "mibII_oid.h"
 
