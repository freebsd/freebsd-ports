--- mib.c.orig	Mon Jul 10 19:18:51 2000
+++ mib.c	Sat Mar 30 19:15:41 2002
@@ -1,4 +1,6 @@
 #include <sys/types.h>
+#include <netinet/in.h>
+
 #ifdef HAVE_UCD_SNMP_TOOLS_H
 #include <ucd-snmp/tools.h>
 #endif
