--- third_party/boringssl/src/crypto/bn/generic.c.orig	2015-07-22 18:56:54.552496000 -0400
+++ third_party/boringssl/src/crypto/bn/generic.c	2015-07-22 18:59:06.813075000 -0400
@@ -71,6 +71,8 @@
 
 #if defined(OPENSSL_WINDOWS)
 #define alloca _alloca
+#elif defined(__FreeBSD__)
+#include <stdlib.h>
 #else
 #include <alloca.h>
 #endif
