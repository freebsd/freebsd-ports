--- snmplib/callback.c.orig	Tue Jan 25 10:19:39 2005
+++ snmplib/callback.c	Tue Jan 25 10:19:53 2005
@@ -34,6 +34,9 @@
 #include <strings.h>
 #endif
 
+#if HAVE_UNISTD_H
+#include <unistd.h>
+#endif
 #if HAVE_DMALLOC_H
 #include <dmalloc.h>
 #endif
