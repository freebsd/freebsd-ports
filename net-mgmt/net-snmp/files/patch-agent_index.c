--- agent/agent_index.c.orig	Mon Jan 24 09:14:39 2005
+++ agent/agent_index.c	Mon Jan 24 09:14:55 2005
@@ -39,10 +39,6 @@
 #include <netinet/in.h>
 #endif
 
-#if HAVE_DMALLOC_H
-#include <dmalloc.h>
-#endif
-
 #include <net-snmp/net-snmp-includes.h>
 #include <net-snmp/agent/net-snmp-agent-includes.h>
 #include <net-snmp/agent/agent_callbacks.h>
