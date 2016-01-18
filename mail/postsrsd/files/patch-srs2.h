--- srs2.h.orig	2015-12-13 08:56:05 UTC
+++ srs2.h
@@ -23,7 +23,7 @@
 #ifdef __APPLE__
     #include <sys/types.h>
 #endif
-
+#include <time.h>
 
 #ifndef __BEGIN_DECLS
 #define __BEGIN_DECLS
