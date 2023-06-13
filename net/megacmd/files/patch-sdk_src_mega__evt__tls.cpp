--- sdk/src/mega_evt_tls.cpp.orig	2023-06-13 08:00:40 UTC
+++ sdk/src/mega_evt_tls.cpp
@@ -64,9 +64,13 @@ static void tls_begin(void)
 {
     SSL_library_init();
     SSL_load_error_strings();
+#if OPENSSL_VERSION_NUMBER >= 0x30000000L
+    OpenSSL_add_all_algorithms();
+#else
     ERR_load_BIO_strings();
     OpenSSL_add_all_algorithms();
     ERR_load_crypto_strings();
+#endif
 }
 
 evt_tls_t *evt_ctx_get_tls(evt_ctx_t *d_eng)
