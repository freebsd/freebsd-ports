--- QuantisExtensions/QuantisExtractor_C.c.orig	2012-09-24 15:42:36.000000000 +0200
+++ QuantisExtensions/QuantisExtractor_C.c	2012-09-24 15:42:56.000000000 +0200
@@ -53,7 +53,11 @@
 #include "../Quantis/Conversion.h"
 #include <stdio.h>
 #include <math.h>
-#include <malloc.h>
+#ifdef HAVE_MALLOC_H
+# include <malloc.h>
+#else
+# include <stdlib.h>
+#endif
 
 
 /* Size of the buffer used for QuantisReadXXX methods */
