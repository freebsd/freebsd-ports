--- src/include/util/bitvector.h.orig	Tue Dec 16 17:41:38 2003
+++ src/include/util/bitvector.h	Tue Dec 16 17:45:12 2003
@@ -5,7 +5,11 @@
 extern "C" {
 #endif
 
+#ifdef HAVE_STDINT_H
 #include <stdint.h>
+#else
+#include <inttypes.h>
+#endif
 
 #ifndef true
 #define true 1
