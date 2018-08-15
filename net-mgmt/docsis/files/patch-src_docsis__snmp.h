--- src/docsis_snmp.h.orig	2015-10-18 20:28:25 UTC
+++ src/docsis_snmp.h
@@ -25,12 +25,20 @@
 #ifndef _DOCSIS_SNMP_H
 #define _DOCSIS_SNMP_H
 
+#include <stdlib.h>
+
 #include <net-snmp/net-snmp-config.h>
 #include <net-snmp/utilities.h>
 #include <net-snmp/config_api.h>
 #include <net-snmp/output_api.h>
 #include <net-snmp/mib_api.h>
 
+#undef PACKAGE_BUGREPORT
+#undef PACKAGE_NAME
+#undef PACKAGE_STRING
+#undef PACKAGE_TARNAME
+#undef PACKAGE_VERSION
+
 #include "docsis.h"
 
 unsigned int encode_vbind ( char *oid_string, char oid_asntype, union t_val *value,
