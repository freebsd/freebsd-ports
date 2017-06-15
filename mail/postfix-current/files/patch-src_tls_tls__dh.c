PR 216732: Fix build with libressl < 2.5.1
=========================================================
--- src/tls/tls_dh.c.orig	2016-12-26 23:47:24 UTC
+++ src/tls/tls_dh.c
@@ -94,7 +94,7 @@
 #define TLS_INTERNAL
 #include <tls.h>
 #include <openssl/dh.h>
-#if OPENSSL_VERSION_NUMBER >= 0x1000200fUL && !defined(OPENSSL_NO_ECDH)
+#if OPENSSL_VERSION_NUMBER >= 0x1000200fUL && !defined(OPENSSL_NO_ECDH) && !defined(LIBRESSL_VERSION_NUMBER)
 #include <openssl/ec.h>
 #endif
 
@@ -244,7 +244,7 @@ DH     *tls_tmp_dh_cb(SSL *unused_ssl, i
 
 void    tls_auto_eecdh_curves(SSL_CTX *ctx)
 {
-#if OPENSSL_VERSION_NUMBER >= 0x1000200fUL && !defined(OPENSSL_NO_ECDH)
+#if OPENSSL_VERSION_NUMBER >= 0x1000200fUL && !defined(OPENSSL_NO_ECDH) && !defined(LIBRESSL_VERSION_NUMBER)
     SSL_CTX *tmpctx;
     int    *nids;
     int     space = 5;
@@ -337,14 +337,14 @@ void    tls_set_eecdh_curve(SSL_CTX *ser
 #define TLS_EECDH_NONE		1
 #define TLS_EECDH_STRONG	2
 #define TLS_EECDH_ULTRA		3
-#if OPENSSL_VERSION_NUMBER >= 0x1000200fUL
+#if OPENSSL_VERSION_NUMBER >= 0x1000200fUL && !defined(LIBRESSL_VERSION_NUMBER)
 #define TLS_EECDH_AUTO		4
 #endif
     static NAME_CODE eecdh_table[] = {
 	"none", TLS_EECDH_NONE,
 	"strong", TLS_EECDH_STRONG,
 	"ultra", TLS_EECDH_ULTRA,
-#if OPENSSL_VERSION_NUMBER >= 0x1000200fUL
+#if OPENSSL_VERSION_NUMBER >= 0x1000200fUL && !defined(LIBRESSL_VERSION_NUMBER)
 	"auto", TLS_EECDH_AUTO,
 #endif
 	0, TLS_EECDH_INVALID,
@@ -364,7 +364,7 @@ void    tls_set_eecdh_curve(SSL_CTX *ser
     case TLS_EECDH_ULTRA:
 	curve = var_tls_eecdh_ultra;
 	break;
-#if OPENSSL_VERSION_NUMBER >= 0x1000200fUL
+#if OPENSSL_VERSION_NUMBER >= 0x1000200fUL && !defined(LIBRESSL_VERSION_NUMBER)
     case TLS_EECDH_AUTO:
 	tls_auto_eecdh_curves(server_ctx);
 	return;
