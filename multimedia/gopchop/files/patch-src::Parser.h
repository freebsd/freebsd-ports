--- src/Parser.h.orig	Fri Jul 12 00:30:21 2002
+++ src/Parser.h	Fri Jul 12 00:32:50 2002
@@ -42,7 +42,9 @@
 // strlen
 #include <string.h>
 
+#ifdef HAVE_STDINT_H
 #include <stdint.h>
+#endif
 
 #include "List.h"
 
