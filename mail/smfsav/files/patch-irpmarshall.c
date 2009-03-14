--- ../src/lib/irs/irpmarshall.c.orig	2009-02-22 15:17:43.000000000 +0000
+++ ../src/lib/irs/irpmarshall.c	2009-02-22 15:25:53.000000000 +0000
@@ -89,6 +89,12 @@
 
 #include "port_after.h"
 
+#if defined(__FreeBSD__)
+#include <osreldate.h>
+#if __FreeBSD_version >= 800058 || __FreeBSD_version >= 701101 && __FreeBSD_version < 800000
+#define HAVE_STRNDUP 1
+#endif
+#endif
 
 #ifndef HAVE_STRNDUP
 static char    *strndup(const char *str, size_t len);

