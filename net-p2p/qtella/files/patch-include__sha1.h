--- include/sha1.h.orig	Fri May 21 01:14:16 2004
+++ include/sha1.h	Mon Jan 29 22:02:09 2007
@@ -5,7 +5,12 @@
 extern "C" {
 #endif
 
+#ifdef HAVE_STDINT_H
 #include <stdint.h>
+#else
+#include <inttypes.h>
+#define int_least16_t int16_t
+#endif
 /*
  * If you do not have the ISO standard stdint.h header file, then you
  * must typdef the following:
