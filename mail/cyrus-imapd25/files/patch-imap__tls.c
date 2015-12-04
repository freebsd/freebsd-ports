--- imap/tls.c.orig	2015-11-30 06:30:33 UTC
+++ imap/tls.c
@@ -683,7 +683,9 @@ EXPORTED int     tls_init_serverengine(c
     off |= SSL_OP_ALL;            /* Work around all known bugs */
     off |= SSL_OP_NO_SSLv2;       /* Disable insecure SSLv2 */
     off |= SSL_OP_NO_SSLv3;       /* Disable insecure SSLv3 */
+#if (OPENSSL_VERSION_NUMBER >= 0x1000000fL)
     off |= SSL_OP_NO_COMPRESSION; /* Disable TLS compression */
+#endif // (OPENSSL_VERSION_NUMBER >= 0x1000000fL)
 
     const char *tls_versions = config_getstring(IMAPOPT_TLS_VERSIONS);
 
@@ -1399,7 +1401,9 @@ HIDDEN int tls_init_clientengine(int ver
     off |= SSL_OP_ALL;            /* Work around all known bugs */
     off |= SSL_OP_NO_SSLv2;       /* Disable insecure SSLv2 */
     off |= SSL_OP_NO_SSLv3;       /* Disable insecure SSLv3 */
+#if (OPENSSL_VERSION_NUMBER >= 0x1000000fL)
     off |= SSL_OP_NO_COMPRESSION; /* Disable TLS compression */
+#endif // (OPENSSL_VERSION_NUMBER >= 0x1000000fL)
 
     SSL_CTX_set_options(c_ctx, off);
     SSL_CTX_set_info_callback(c_ctx, apps_ssl_info_callback);
