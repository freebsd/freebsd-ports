--- include/net-snmp/system/freebsd15.h.orig	2024-03-02 16:01:17 UTC
+++ include/net-snmp/system/freebsd15.h
@@ -0,0 +1,3 @@
+/* freebsd14 is a superset of freebsd13 */
+#include "freebsd13.h"
+#define freebsd13 freebsd13
