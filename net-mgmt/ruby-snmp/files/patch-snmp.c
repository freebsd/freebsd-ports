--- snmp.c.orig	Mon Jul 10 19:18:51 2000
+++ snmp.c	Sat Mar 30 19:15:26 2002
@@ -1,5 +1,6 @@
 #include <errno.h>
 #include <sys/types.h>
+#include <netinet/in.h>
 
 #ifdef HAVE_UCD_SNMP_TOOLS_H
 #include <ucd-snmp/tools.h>
