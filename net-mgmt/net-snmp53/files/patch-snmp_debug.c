--- snmplib/snmp_debug.c.orig	Tue Jan 25 10:10:49 2005
+++ snmplib/snmp_debug.c	Tue Jan 25 10:11:06 2005
@@ -22,6 +22,9 @@
 #include <winsock.h>
 #endif
 
+#if HAVE_UNISTD_H
+#include <unistd.h>
+#endif
 #if HAVE_DMALLOC_H
 #include <dmalloc.h>
 #endif
