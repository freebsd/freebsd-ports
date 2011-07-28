--- ./agent/agent_read_config.c.orig	2011-07-07 15:30:36.000000000 -0700
+++ agent/agent_read_config.c	2011-07-07 15:35:57.000000000 -0700
@@ -5,7 +5,11 @@
 #include <net-snmp/net-snmp-config.h>
 #include <net-snmp/net-snmp-features.h>
 
+#if HAVE_SYS_PARAM_H
+#include <sys/param.h>
+#else
 #include <sys/types.h>
+#endif
 #if HAVE_STDLIB_H
 #include <stdlib.h>
 #endif
