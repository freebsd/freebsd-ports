--- include/cga_keyutils.h.orig	2014-08-20 04:17:35.000000000 +0900
+++ include/cga_keyutils.h	2014-08-20 04:17:58.000000000 +0900
@@ -36,6 +36,9 @@
 #include <openssl/x509.h>
 #include <openssl/evp.h>
 #include <openssl/stack.h>
+#ifndef STACK
+#define	STACK _STACK
+#endif
 #include <cga.h>
 
 extern int cga_add_key(cga_ctx_t *, EVP_PKEY *, int, uint16_t);
