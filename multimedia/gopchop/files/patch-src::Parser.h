--- src/Parser.h.orig	Mon Apr  7 07:24:42 2003
+++ src/Parser.h	Tue May  6 21:36:18 2003
@@ -42,7 +42,9 @@
 // strlen
 #include <string.h>
 
+#ifdef HAVE_STDINT_H
 #include <stdint.h>
+#endif
 
 #include "List.h"
 
