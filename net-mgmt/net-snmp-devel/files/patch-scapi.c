--- snmplib/scapi.c.orig	Tue Jan 25 10:18:44 2005
+++ snmplib/scapi.c	Tue Jan 25 10:19:01 2005
@@ -46,6 +46,9 @@
 #include <netinet/in.h>
 #endif
 
+#if HAVE_UNISTD_H
+#include <unistd.h>
+#endif
 #if HAVE_DMALLOC_H
 #include <dmalloc.h>
 #endif
