--- cyberflex.c.orig	Thu Jun 19 23:37:35 2003
+++ cyberflex.c	Mon Sep 29 00:58:56 2003
@@ -48,7 +48,13 @@
 #define SHA1Init SHA1_Init
 #define SHA1Update SHA1_Update
 #define SHA1Final SHA1_Final
-#else /* __linux */
+#elif defined(__FreeBSD__)
+#define SHA1_CTX SHA_CTX
+#define SHA1Init SHA1_Init
+#define SHA1Update SHA1_Update
+#define SHA1Final SHA1_Final
+#include <sha.h>
+#else
 #include <sha1.h>
 #endif
 #else
