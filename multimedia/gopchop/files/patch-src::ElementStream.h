--- src/ElementStream.h.orig	Fri Jul 12 00:30:21 2002
+++ src/ElementStream.h	Fri Jul 12 00:33:44 2002
@@ -29,7 +29,10 @@
 
 #include "config.h"
 #include "Vector.h"
+
+#ifdef HAVE_STDINT_H
 #include <stdint.h>
+#endif
 
 class ElementStream: public Vector
 {
