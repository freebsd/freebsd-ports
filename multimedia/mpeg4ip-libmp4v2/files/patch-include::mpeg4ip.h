--- include/mpeg4ip.h.orig	Wed Sep 29 14:43:52 2004
+++ include/mpeg4ip.h	Wed Sep 29 14:44:10 2004
@@ -160,14 +160,14 @@
 #include <errno.h>
 #include <stdlib.h>
 
-#ifdef HAVE_INTTYPES_H
 #include <inttypes.h>
-#endif
 #ifdef HAVE_STDINT_H
 #include <stdint.h>
 #endif
+#if 0
 #if !defined(HAVE_INTTYPES_H) || !defined(HAVE_STDINT_H)
 #error "Don't have stdint.h or inttypes.h - no way to get uint8_t"
+#endif
 #endif
 
 #include <unistd.h>
