--- src/ElementStream.h.orig	Thu Jan 17 06:32:23 2002
+++ src/ElementStream.h	Tue May  6 21:35:30 2003
@@ -29,7 +29,10 @@
 
 #include "config.h"
 #include "Vector.h"
+
+#ifdef HAVE_STDINT_H
 #include <stdint.h>
+#endif
 
 class ElementStream: public Vector
 {
