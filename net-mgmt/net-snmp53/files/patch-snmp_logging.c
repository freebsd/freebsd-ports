--- snmplib/snmp_logging.c.orig	Tue Jan 25 10:14:41 2005
+++ snmplib/snmp_logging.c	Tue Jan 25 10:15:05 2005
@@ -65,6 +65,9 @@
 #include <varargs.h>
 #endif
 
+#if HAVE_UNISTD_H
+#include <unistd.h>
+#endif
 #if HAVE_DMALLOC_H
 #include <dmalloc.h>
 #endif
