--- src/assuan-domain-connect.c.orig	Mon Apr 19 10:41:29 2004
+++ src/assuan-domain-connect.c	Sun Oct 10 22:26:54 2004
@@ -33,6 +33,12 @@
 #include <fcntl.h>
 #include <string.h>
 #include <assert.h>
+#ifdef __FreeBSD__
+#include <sys/param.h>
+#if __FreeBSD_version < 503001
+#include <isc/eventlib.h>
+#endif
+#endif
 
 #include "assuan-defs.h"
 
