--- agent/mibgroup/mibII/sysORTable.c.orig	Mon Jan 24 08:27:58 2005
+++ agent/mibgroup/mibII/sysORTable.c	Mon Jan 24 08:28:10 2005
@@ -34,10 +34,6 @@
 #include <netinet/in.h>
 #endif
 
-#if HAVE_DMALLOC_H
-#include <dmalloc.h>
-#endif
-
 #include <net-snmp/net-snmp-includes.h>
 #include <net-snmp/agent/net-snmp-agent-includes.h>
 #include <net-snmp/agent/agent_callbacks.h>
