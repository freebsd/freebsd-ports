--- agent/mibgroup/sctp-mib/sctpTables_common.c.orig	2009-03-07 23:32:28.000000000 +0900
+++ agent/mibgroup/sctp-mib/sctpTables_common.c	2009-03-07 23:33:09.000000000 +0900
@@ -1,3 +1,6 @@
+#include <net-snmp/net-snmp-config.h>
+#include <net-snmp/net-snmp-includes.h>
+#include <net-snmp/agent/net-snmp-agent-includes.h>
 #include "sctpTables_common.h"
 #include "sctpAssocTable.h"
 #include "sctpAssocRemAddrTable.h"
