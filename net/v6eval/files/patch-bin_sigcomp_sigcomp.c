--- bin/sigcomp/sigcomp.c.orig	2008-04-03 09:34:43.000000000 +0900
+++ bin/sigcomp/sigcomp.c	2013-06-16 11:06:24.000000000 +0900
@@ -57,6 +57,9 @@
 
 #include <openssl/rsa.h>
 
+#ifdef OPENSSL_NO_MD2
+const EVP_MD *EVP_md2(void);
+#endif
 
 #ifdef DEBUG
 #ifndef dbg
