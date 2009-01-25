--- agent/mibgroup/sctp-mib/sctpTables_common.h.orig	2009-01-23 23:42:34.000000000 +0900
+++ agent/mibgroup/sctp-mib/sctpTables_common.h	2009-01-23 23:43:11.000000000 +0900
@@ -5,6 +5,10 @@
 #include <net-snmp/net-snmp-includes.h>
 #include <net-snmp/agent/net-snmp-agent-includes.h>
 
+#if defined(freebsd7)
+#define netsnmp_table_registration_info_free SNMP_FREE
+#endif
+
 #define SCTP_IPADDRESS_SIZE 16
 #define SCTP_HOSTNAME_SIZE 255
 
