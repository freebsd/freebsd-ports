--- tests/COMMON/num.h.orig	2018-10-08 17:28:33 UTC
+++ tests/COMMON/num.h
@@ -42,7 +42,7 @@
 #endif
 #define Sprimme CONCAT(SCALAR_PRE,primme)
 #define Sprimme_svds CONCAT(SCALAR_PRE,primme_svds)
-#if !(defined (__APPLE__) && defined (__MACH__))
+#if !(defined (__APPLE__) && defined (__MACH__)) && !defined(__FreeBSD__)
 #  include <malloc.h> /* malloc */
 #endif
 #include <stdlib.h>   /* malloc, free */
