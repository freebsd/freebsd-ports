--- snmp_mibII/mibII_route.c.orig	Wed Oct  5 14:18:53 2005
+++ snmp_mibII/mibII_route.c	Wed Oct  5 14:18:16 2005
@@ -30,7 +30,11 @@
  *
  * Routing table
  */
+#ifdef HAVE_SYSTREE_H
 #include <sys/tree.h>
+#else
+#include "tree.h"
+#endif
 #include "mibII.h"
 #include "mibII_oid.h"
 
