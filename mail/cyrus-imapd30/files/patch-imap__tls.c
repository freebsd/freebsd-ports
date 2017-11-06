--- imap/tls.c.orig	2016-07-22 01:55:57 UTC
+++ imap/tls.c
@@ -222,7 +222,7 @@ static RSA *tmp_rsa_cb(SSL * s __attribu
 }
 #endif
 
-#if OPENSSL_VERSION_NUMBER < 0x10100000L
+#if OPENSSL_VERSION_NUMBER < 0x10100000L || defined(LIBRESSL_VERSION_NUMBER)
 /* replacements for new 1.1 API accessors */
 /* XXX probably put these somewhere central */
 static int DH_set0_pqg(DH *dh, BIGNUM *p, BIGNUM *q, BIGNUM *g)
@@ -723,7 +723,9 @@ EXPORTED int     tls_init_serverengine(c
     off |= SSL_OP_ALL;            /* Work around all known bugs */
     off |= SSL_OP_NO_SSLv2;       /* Disable insecure SSLv2 */
     off |= SSL_OP_NO_SSLv3;       /* Disable insecure SSLv3 */
+#if (OPENSSL_VERSION_NUMBER >= 0x1000000fL)
     off |= SSL_OP_NO_COMPRESSION; /* Disable TLS compression */
+#endif // (OPENSSL_VERSION_NUMBER >= 0x1000000fL)
 
     const char *tls_versions = config_getstring(IMAPOPT_TLS_VERSIONS);
 
@@ -1441,7 +1443,9 @@ HIDDEN int tls_init_clientengine(int ver
     off |= SSL_OP_ALL;            /* Work around all known bugs */
     off |= SSL_OP_NO_SSLv2;       /* Disable insecure SSLv2 */
     off |= SSL_OP_NO_SSLv3;       /* Disable insecure SSLv3 */
+#if (OPENSSL_VERSION_NUMBER >= 0x1000000fL)
     off |= SSL_OP_NO_COMPRESSION; /* Disable TLS compression */
+#endif // (OPENSSL_VERSION_NUMBER >= 0x1000000fL)
 
     SSL_CTX_set_options(c_ctx, off);
     SSL_CTX_set_info_callback(c_ctx, apps_ssl_info_callback);
