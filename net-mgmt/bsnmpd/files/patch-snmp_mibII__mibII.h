--- snmp_mibII/mibII.h     Wed Oct  5 11:56:04 2005
+++ snmp_mibII/mibII.h     Wed Oct  5 11:56:57 2005
@@ -57,6 +57,13 @@
 #include "mibII_tree.h"


+#ifndef SA_SIZE
+#define SA_SIZE(sa)                                             \
+    (  (!(sa) || ((struct sockaddr *)(sa))->sa_len == 0) ?      \
+        sizeof(long)            :                               \
+        1 + ( (((struct sockaddr *)(sa))->sa_len - 1) | (sizeof(long) - 1) ) )
+#endif
+
 /*
  * Interface list and flags.
  */
