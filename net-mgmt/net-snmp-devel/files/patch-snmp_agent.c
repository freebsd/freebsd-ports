--- agent/snmp_agent.c.orig	Sun Oct  6 05:41:58 2002
+++ agent/snmp_agent.c	Sun Oct  6 18:19:12 2002
@@ -71,6 +71,7 @@
 
 #ifdef USE_LIBWRAP
 #include <tcpd.h>
+#include <syslog.h>
 int             allow_severity = LOG_INFO;
 int             deny_severity = LOG_WARNING;
 #endif
