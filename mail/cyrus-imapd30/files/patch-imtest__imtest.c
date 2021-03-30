--- imtest/imtest.c.orig	2015-11-30 06:30:33 UTC
+++ imtest/imtest.c
@@ -503,7 +503,9 @@ static int tls_init_clientengine(int ver
     off |= SSL_OP_ALL;            /* Work around all known bugs */
     off |= SSL_OP_NO_SSLv2;       /* Disable insecure SSLv2 */
     off |= SSL_OP_NO_SSLv3;       /* Disable insecure SSLv3 */
+#if defined(SSL_OP_NO_COMPRESSION)
     off |= SSL_OP_NO_COMPRESSION; /* Disable TLS compression */
+#endif
     SSL_CTX_set_options(tls_ctx, off);
     SSL_CTX_set_info_callback(tls_ctx, apps_ssl_info_callback);
     
