--- include/net-snmp/net-snmp-includes.h.orig	Mon Jan 24 08:24:47 2005
+++ include/net-snmp/net-snmp-includes.h	Mon Jan 24 08:25:11 2005
@@ -49,6 +49,10 @@
 # endif
 #endif
 
+#if HAVE_UNISTD_H
+#include <unistd.h>
+#endif
+
 /*
  * Must be right after system headers, but before library code for best usage 
  */
