--- include/net-snmp/system/freebsd13.h.orig	2019-03-07 15:59:25 UTC
+++ include/net-snmp/system/freebsd13.h
@@ -0,0 +1,3 @@
+/* freebsd12 is a superset of freebsd11 */
+#include "freebsd11.h"
+#define freebsd11 freebsd11
