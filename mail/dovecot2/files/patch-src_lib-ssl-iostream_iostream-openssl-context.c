--- src/lib-ssl-iostream/iostream-openssl-context.c.orig        2014-02-04 22:28:38.000000000 +0100
+++ src/lib-ssl-iostream/iostream-openssl-context.c     2014-09-29 11:16:39.478263787 +0200
@@ -416,7 +416,7 @@
        return 0;
 }

-#if defined(HAVE_ECDH) && OPENSSL_VERSION_NUMBER < 0x10002000L
+#if defined(HAVE_ECDH) && !defined(SSL_CTRL_SET_ECDH_AUTO)
 static int
 ssl_proxy_ctx_get_pkey_ec_curve_name(const struct ssl_iostream_settings *set,
                                     int *nid_r, const char **error_r)
@@ -446,7 +446,7 @@
                                const struct ssl_iostream_settings *set ATTR_UNUSED,
                                const char **error_r ATTR_UNUSED)
 {
-#if defined(HAVE_ECDH) && OPENSSL_VERSION_NUMBER < 0x10002000L
+#if defined(HAVE_ECDH) && !defined(SSL_CTRL_SET_ECDH_AUTO)
        EC_KEY *ecdh;
        int nid;
        const char *curve_name;
@@ -459,7 +459,7 @@
           used instead of ECDHE, do not reuse the same ECDH key pair for
           different sessions. This option improves forward secrecy. */
        SSL_CTX_set_options(ssl_ctx, SSL_OP_SINGLE_ECDH_USE);
-#if OPENSSL_VERSION_NUMBER >= 0x10002000L
+#ifdef SSL_CTRL_SET_ECDH_AUTO
        /* OpenSSL >= 1.0.2 automatically handles ECDH temporary key parameter
           selection. */
        SSL_CTX_set_ecdh_auto(ssl_ctx, 1);
