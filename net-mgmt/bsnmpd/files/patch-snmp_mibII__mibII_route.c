--- snmp_mibII/mibII_route.c.orig	Mon Apr 24 23:53:40 2006
+++ snmp_mibII/mibII_route.c	Mon Apr 24 23:53:51 2006
@@ -31,13 +31,7 @@
  * Routing table
  */
 #include "support.h"
-
-#ifdef HAVE_SYS_TREE_H
-#include <sys/tree.h>
-#else
 #include "tree.h"
-#endif
-
 #include "mibII.h"
 #include "mibII_oid.h"
 
