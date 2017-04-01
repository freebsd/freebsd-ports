--- src/sslinfo.c.orig	2016-03-23 18:06:39 UTC
+++ src/sslinfo.c
@@ -25,6 +25,13 @@
 #ifdef HAVE_OPENSSL
 #include "ssl_private.h"
 
+#ifdef LIBRESSL_VERSION_NUMBER
+int X509_get_signature_nid(const X509 *x)
+{
+    return OBJ_obj2nid(x->sig_alg->algorithm);
+}
+#endif
+
 static const char *hex_basis = "0123456789ABCDEF";
 
 static char *convert_to_hex(const void *buf, size_t len)
