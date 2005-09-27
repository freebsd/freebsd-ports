--- lib/snmp.c.orig	Fri Sep 23 08:48:16 2005
+++ lib/snmp.c	Fri Sep 23 08:47:34 2005
@@ -36,7 +36,11 @@
 #include <stdlib.h>
 #include <stddef.h>
 #include <stdarg.h>
+#ifdef HAVE_STDINT_H
 #include <stdint.h>
+#elif defined(HAVE_INTTYPES_H)
+#include <inttypes.h>
+#endif
 #include <string.h>
 #include <ctype.h>
 #include <netdb.h>
