--- snmplib/mib.c.orig	Tue Jan 25 10:01:11 2005
+++ snmplib/mib.c	Tue Jan 25 10:02:02 2005
@@ -75,6 +75,9 @@
 #include <winsock.h>
 #endif
 
+#if HAVE_UNISTD_H
+#include <unistd.h>
+#endif
 #if HAVE_DMALLOC_H
 #include <dmalloc.h>
 #endif
