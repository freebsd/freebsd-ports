--- agent/agent_registry.c.orig	Mon Jan 24 09:14:00 2005
+++ agent/agent_registry.c	Mon Jan 24 09:14:08 2005
@@ -51,10 +51,6 @@
 #include <netinet/in.h>
 #endif
 
-#if HAVE_DMALLOC_H
-#include <dmalloc.h>
-#endif
-
 #include <net-snmp/net-snmp-includes.h>
 #include <net-snmp/agent/net-snmp-agent-includes.h>
 #include <net-snmp/agent/agent_callbacks.h>
