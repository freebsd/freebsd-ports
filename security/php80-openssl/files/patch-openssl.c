--- openssl.c.orig	2020-12-04 10:00:27.778868000 +0000
+++ openssl.c	2020-12-04 10:01:36.820415000 +0000
@@ -6496,7 +6496,7 @@
 	int cipher_mode = EVP_CIPHER_mode(cipher_type);
 	memset(mode, 0, sizeof(struct php_openssl_cipher_mode));
 	switch (cipher_mode) {
-#if PHP_OPENSSL_API_VERSION >= 0x10100
+#ifdef EVP_CIPH_OCB_MODE
 		case EVP_CIPH_GCM_MODE:
 		case EVP_CIPH_OCB_MODE:
 		case EVP_CIPH_CCM_MODE:
