--- snmplib/snmp_transport.c.orig	Tue Jan 25 10:21:33 2005
+++ snmplib/snmp_transport.c	Tue Jan 25 10:21:52 2005
@@ -12,6 +12,9 @@
 #include <stdlib.h>
 #endif
 
+#if HAVE_UNISTD_H
+#include <unistd.h>
+#endif
 #if HAVE_DMALLOC_H
 #include <dmalloc.h>
 #endif
