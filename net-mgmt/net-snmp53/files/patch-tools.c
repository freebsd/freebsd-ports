--- snmplib/tools.c.orig	Tue Jan 25 10:13:50 2005
+++ snmplib/tools.c	Tue Jan 25 10:14:06 2005
@@ -44,6 +44,9 @@
 #include <arpa/inet.h>
 #endif
 
+#if HAVE_UNISTD_H
+#include <unistd.h>
+#endif
 #if HAVE_DMALLOC_H
 #include <dmalloc.h>
 #endif
