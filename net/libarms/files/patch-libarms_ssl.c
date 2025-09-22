--- libarms/ssl.c.orig	2024-12-04 00:27:42 UTC
+++ libarms/ssl.c
@@ -794,6 +794,9 @@ arms_ssl_cleanup(void)
 {
 	CRYPTO_cleanup_all_ex_data();
 	ERR_free_strings();
+/* <= 1.0.1f = old API, 1.0.1g+ = new API */
+#if OPENSSL_VERSION_NUMBER <= 0x1000106fL
 	ERR_remove_state(0);
+#endif
 	EVP_cleanup();
 }
