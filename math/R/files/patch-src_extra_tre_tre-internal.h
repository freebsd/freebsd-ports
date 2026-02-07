--- src/extra/tre/tre-internal.h.orig	2016-07-23 16:50:17 UTC
+++ src/extra/tre/tre-internal.h
@@ -18,6 +18,7 @@
 #endif /* !HAVE_WCTYPE_H */
 
 #include <ctype.h>
+#include <stdint.h>
 #include "tre.h"
 
 #ifdef TRE_DEBUG
