--- snmplib/default_store.c.orig	Tue Jan 25 10:20:31 2005
+++ snmplib/default_store.c	Tue Jan 25 10:20:47 2005
@@ -145,6 +145,9 @@
 #include <winsock.h>
 #endif
 
+#if HAVE_UNISTD_H
+#include <unistd.h>
+#endif
 #if HAVE_DMALLOC_H
 #include <dmalloc.h>
 #endif
