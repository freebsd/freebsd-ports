--- lib/asn1.c.orig	Thu Sep 22 09:02:07 2005
+++ lib/asn1.c	Thu Sep 22 09:03:46 2005
@@ -35,7 +35,11 @@
 #include <stdlib.h>
 #include <stdarg.h>
 #include <string.h>
+#ifdef HAVE_STDINT_H
 #include <stdint.h>
+#elif defined(HAVE_INTTYPES_H)
+#include <inttypes.h>
+#endif
 #include <assert.h>
 #include "asn1.h"
 
