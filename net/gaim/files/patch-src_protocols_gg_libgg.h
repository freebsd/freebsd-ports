--- src/protocols/gg/libgg.h.orig	Sun May 30 18:01:35 2004
+++ src/protocols/gg/libgg.h	Sun May 30 18:01:58 2004
@@ -29,7 +29,9 @@
   #define INADDR_NONE 0xffffffff
 #endif
 
+#ifdef HAVE_STDINT_H
 #include <stdint.h>
+#endif
 #include <sys/types.h>
 
 /*
