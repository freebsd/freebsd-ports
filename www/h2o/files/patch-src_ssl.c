--- src/ssl.c.orig	2023-08-08 09:33:37 UTC
+++ src/ssl.c
@@ -1182,7 +1182,9 @@ void init_openssl(void)
     SSL_library_init();
     OpenSSL_add_all_algorithms();
 #if H2O_CAN_OSSL_ASYNC
+#if OPENSSL_VERSION_NUMBER < 0x30000000L
     ERR_load_ASYNC_strings();
+#endif
 #endif
 
     /* When using OpenSSL >= 3.0, load legacy provider so that blowfish can be used for 64-bit QUIC CIDs. */
