--- snmplib/snmp_auth.c.orig	Tue Jan 25 10:08:14 2005
+++ snmplib/snmp_auth.c	Tue Jan 25 10:08:34 2005
@@ -63,6 +63,9 @@
 #include <arpa/inet.h>
 #endif
 
+#if HAVE_UNISTD_H
+#include <unistd.h>
+#endif
 #if HAVE_DMALLOC_H
 #include <dmalloc.h>
 #endif
