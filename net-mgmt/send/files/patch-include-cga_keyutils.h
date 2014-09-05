--- include/cga_keyutils.h.orig	2010-08-28 17:58:02.000000000 +0900
+++ include/cga_keyutils.h	2014-08-30 01:53:41.000000000 +0900
@@ -36,6 +36,9 @@
 #include <openssl/x509.h>
 #include <openssl/evp.h>
 #include <openssl/stack.h>
+#if OPENSSL_VERSION_NUMBER >= 0x0090900fL
+#define	STACK _STACK
+#endif
 #include <cga.h>
 
 extern int cga_add_key(cga_ctx_t *, EVP_PKEY *, int, uint16_t);
