--- agent/mibgroup/agentx/subagent.c.orig	Mon Jan 24 09:17:08 2005
+++ agent/mibgroup/agentx/subagent.c	Mon Jan 24 09:17:12 2005
@@ -36,10 +36,6 @@
 #include <netinet/in.h>
 #endif
 
-#if HAVE_DMALLOC_H
-#include <dmalloc.h>
-#endif
-
 #include <net-snmp/net-snmp-includes.h>
 #include <net-snmp/agent/net-snmp-agent-includes.h>
 #include <net-snmp/library/snmp_assert.h>
