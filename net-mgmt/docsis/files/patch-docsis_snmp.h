# $FreeBSD$
--- src/docsis_snmp.h.orig	Wed Mar 17 08:01:37 2004
+++ src/docsis_snmp.h	Sun Jun 10 18:27:16 2007
@@ -24,11 +24,19 @@
 #ifndef _DOCSIS_SNMP_H
 #define _DOCSIS_SNMP_H
 
+#include <stdlib.h>
+
 #include <net-snmp/net-snmp-config.h>
 #include <net-snmp/utilities.h>
 #include <net-snmp/config_api.h>
 #include <net-snmp/output_api.h>
 #include <net-snmp/mib_api.h>
+
+#undef PACKAGE_BUGREPORT
+#undef PACKAGE_NAME
+#undef PACKAGE_STRING
+#undef PACKAGE_TARNAME
+#undef PACKAGE_VERSION
 
 #include "docsis.h"
 
