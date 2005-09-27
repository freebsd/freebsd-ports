--- lib/snmpagent.c.orig	Thu Sep 22 09:06:25 2005
+++ lib/snmpagent.c	Thu Sep 22 09:07:19 2005
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
 
 #include "asn1.h"
