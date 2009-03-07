--- agent/mibgroup/sctp-mib/sctpTables_common.h.orig	2008-08-18 06:29:11.000000000 +0900
+++ agent/mibgroup/sctp-mib/sctpTables_common.h	2009-02-28 14:06:27.000000000 +0900
@@ -1,9 +1,9 @@
 #ifndef SCTP_TABLES_COMMON_H
 #define SCTP_TABLES_COMMON_H
 
-#include <net-snmp/net-snmp-config.h>
-#include <net-snmp/net-snmp-includes.h>
-#include <net-snmp/agent/net-snmp-agent-includes.h>
+#if defined(freebsd7)
+#define netsnmp_table_registration_info_free SNMP_FREE
+#endif
 
 #define SCTP_IPADDRESS_SIZE 16
 #define SCTP_HOSTNAME_SIZE 255
