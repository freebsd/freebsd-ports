--- agent/mibgroup/sctp-mib/sctpTables_common.h.orig	2010-06-01 10:58:20.000000000 -0300
+++ agent/mibgroup/sctp-mib/sctpTables_common.h	2010-06-01 10:18:02.000000000 -0300
@@ -1,7 +1,7 @@
 #ifndef SCTP_TABLES_COMMON_H
 #define SCTP_TABLES_COMMON_H
 
-#if defined(freebsd8) || defined(freebsd7)
+#if defined(freebsd9) || defined(freebsd8) || defined(freebsd7)
 #define netsnmp_table_registration_info_free SNMP_FREE
 #endif
 
