--- ./agent/snmp_vars.c.orig	2011-07-07 15:37:08.000000000 -0700
+++ agent/snmp_vars.c	2011-07-07 15:37:14.000000000 -0700
@@ -62,6 +62,9 @@
  */
 
 #include <net-snmp/net-snmp-config.h>
+#if HAVE_SYS_PARAM_H
+#include <sys/param.h>
+#endif
 #if HAVE_STRING_H
 #include <string.h>
 #endif
