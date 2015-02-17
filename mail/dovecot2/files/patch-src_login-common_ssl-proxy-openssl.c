--- src/login-common/ssl-proxy-openssl.c.orig   2014-05-07 16:23:24.000000000 +0200
+++ src/login-common/ssl-proxy-openssl.c        2014-09-29 11:08:25.640320429 +0200
@@ -79,6 +79,7 @@
        unsigned int cert_received:1;
        unsigned int cert_broken:1;
        unsigned int client_proxy:1;
+       unsigned int flushing:1;
 };

 struct ssl_parameters {
@@ -125,7 +126,7 @@

 static void ssl_proxy_ctx_set_crypto_params(SSL_CTX *ssl_ctx,
                                             const struct master_service_ssl_settings *set);
-#if defined(HAVE_ECDH) && OPENSSL_VERSION_NUMBER < 0x10002000L
+#if defined(HAVE_ECDH) && !defined(SSL_CTRL_SET_ECDH_AUTO)
 static int ssl_proxy_ctx_get_pkey_ec_curve_name(const struct master_service_ssl_settings *set);
 #endif

@@ -806,10 +807,20 @@
        i_free(proxy);
 }

+static void ssl_proxy_flush(struct ssl_proxy *proxy)
+{
+       /* this is pretty kludgy. mainly this is just for flushing the final
+          LOGOUT command output. */
+       plain_read(proxy);
+       ssl_step(proxy);
+}
+
 void ssl_proxy_destroy(struct ssl_proxy *proxy)
 {
-       if (proxy->destroyed)
+       if (proxy->destroyed || proxy->flushing)
                return;
+       proxy->flushing = TRUE;
+       ssl_proxy_flush(proxy);
        proxy->destroyed = TRUE;

        ssl_proxy_count--;
@@ -1024,7 +1035,7 @@
 ssl_proxy_ctx_set_crypto_params(SSL_CTX *ssl_ctx,
        const struct master_service_ssl_settings *set ATTR_UNUSED)
 {
-#if defined(HAVE_ECDH) && OPENSSL_VERSION_NUMBER < 0x10002000L
+#if defined(HAVE_ECDH) && !defined(SSL_CTRL_SET_ECDH_AUTO)
        EC_KEY *ecdh;
        int nid;
        const char *curve_name;
@@ -1037,7 +1048,7 @@
           used instead of ECDHE, do not reuse the same ECDH key pair for
           different sessions. This option improves forward secrecy. */
        SSL_CTX_set_options(ssl_ctx, SSL_OP_SINGLE_ECDH_USE);
-#if OPENSSL_VERSION_NUMBER >= 0x10002000L
+#ifdef SSL_CTRL_SET_ECDH_AUTO
        /* OpenSSL >= 1.0.2 automatically handles ECDH temporary key parameter
           selection. */
        SSL_CTX_set_ecdh_auto(ssl_ctx, 1);
@@ -1152,7 +1163,7 @@
        EVP_PKEY_free(pkey);
 }

-#if defined(HAVE_ECDH) && OPENSSL_VERSION_NUMBER < 0x10002000L
+#if defined(HAVE_ECDH) && !defined(SSL_CTRL_SET_ECDH_AUTO)
 static int
 ssl_proxy_ctx_get_pkey_ec_curve_name(const struct master_service_ssl_settings *set)
 {
