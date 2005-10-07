--- snmp_mibII/mibII.c.orig	Thu Jun  9 16:36:52 2005
+++ snmp_mibII/mibII.c	Fri Oct  7 14:21:53 2005
@@ -34,6 +34,12 @@
 #include "mibII_oid.h"
 #include <net/if_types.h>
 
+#ifndef SA_SIZE
+#define SA_SIZE(sa)                                             \
+    (  (!(sa) || ((struct sockaddr *)(sa))->sa_len == 0) ?      \
+        sizeof(long)            :                               \
+        1 + ( (((struct sockaddr *)(sa))->sa_len - 1) | (sizeof(long) - 1) ) )
+#endif
 
 /*****************************/
 
