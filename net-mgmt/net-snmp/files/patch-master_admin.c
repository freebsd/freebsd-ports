--- agent/mibgroup/agentx/master_admin.c.orig	Mon Jan 24 09:18:07 2005
+++ agent/mibgroup/agentx/master_admin.c	Mon Jan 24 09:18:15 2005
@@ -35,9 +35,6 @@
 #if HAVE_SYS_SOCKET_H
 #include <sys/socket.h>
 #endif
-#if HAVE_DMALLOC_H
-#include <dmalloc.h>
-#endif
 
 #include <net-snmp/net-snmp-includes.h>
 #include <net-snmp/agent/net-snmp-agent-includes.h>
