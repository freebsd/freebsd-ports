--- src/ctx.c.orig	2016-06-21 15:06:14 UTC
+++ src/ctx.c
@@ -366,7 +366,7 @@ NOEXPORT int ecdh_init(SERVICE_OPTIONS *
 /**************************************** initialize OpenSSL CONF */
 
 NOEXPORT int conf_init(SERVICE_OPTIONS *section) {
-#if OPENSSL_VERSION_NUMBER>=0x10002000L
+#if OPENSSL_VERSION_NUMBER>=0x10002000L && !defined(LIBRESSL_VERSION_NUMBER)
     SSL_CONF_CTX *cctx;
     NAME_LIST *curr;
     char *cmd, *param;
