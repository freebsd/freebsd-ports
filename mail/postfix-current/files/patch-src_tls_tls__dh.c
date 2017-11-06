$OpenBSD: patch-src_tls_tls_dh_c,v 1.1 2017/03/04 22:09:43 sthen Exp $

Fix building with LibreSSL

--- src/tls/tls_dh.c.orig	2016-12-26 23:47:24 UTC
+++ src/tls/tls_dh.c
@@ -314,7 +314,7 @@ void    tls_auto_eecdh_curves(SSL_CTX *c
      * This is a NOP in OpenSSL 1.1.0 and later, where curves are always
      * auto-negotiated.
      */
-#if OPENSSL_VERSION_NUMBER < 0x10100000UL
+#if OPENSSL_VERSION_NUMBER < 0x10100000UL || defined(LIBRESSL_VERSION_NUMBER)
     if (SSL_CTX_set_ecdh_auto(ctx, 1) <= 0) {
 	msg_warn("failed to enable automatic ECDHE curve selection");
 	tls_print_errors();
