--- snmplib/keytools.c.orig	Tue Jan 25 10:17:48 2005
+++ snmplib/keytools.c	Tue Jan 25 10:18:07 2005
@@ -32,6 +32,9 @@
 #include <strings.h>
 #endif
 
+#if HAVE_UNISTD_H
+#include <unistd.h>
+#endif
 #if HAVE_DMALLOC_H
 #include <dmalloc.h>
 #endif
