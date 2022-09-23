--- src/qjsgiac.c.orig	2021-03-20 11:09:33 UTC
+++ src/qjsgiac.c
@@ -41,6 +41,8 @@
 #include <malloc/malloc.h>
 #elif defined(__linux__)
 #include <malloc.h>
+#elif defined(__FreeBSD__)
+#include <malloc_np.h>
 #endif
 
 #ifdef NSPIRE_NEWLIB
