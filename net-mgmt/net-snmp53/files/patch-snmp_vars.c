--- agent/snmp_vars.c.orig	Mon Jan 24 09:12:09 2005
+++ agent/snmp_vars.c	Mon Jan 24 09:12:23 2005
@@ -136,10 +136,6 @@
 #include <inet/mib2.h>
 #endif
 
-#if HAVE_DMALLOC_H
-#include <dmalloc.h>
-#endif
-
 #include <net-snmp/net-snmp-includes.h>
 #include <net-snmp/agent/net-snmp-agent-includes.h>
 #include <net-snmp/agent/mib_modules.h>
