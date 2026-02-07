Index: modules/md/md_crypt.c
--- modules/md/md_crypt.c.orig
+++ modules/md/md_crypt.c
@@ -71,6 +71,11 @@
 #include <openssl/ct.h>
 #endif
 
+#if defined(LIBRESSL_VERSION_NUMBER)
+#define EVP_PKEY_X25519 NID_X25519
+#define EVP_PKEY_X448 NID_X448
+#endif
+
 static int initialized;
 
 struct md_pkey_t {
