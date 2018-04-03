--- src/ctx.c.orig	2018-04-03 17:45:50 UTC
+++ src/ctx.c
@@ -398,7 +398,7 @@ NOEXPORT int ecdh_init(SERVICE_OPTIONS *
 /**************************************** initialize OpenSSL CONF */
 
 NOEXPORT int conf_init(SERVICE_OPTIONS *section) {
-#if OPENSSL_VERSION_NUMBER>=0x10002000L
+#if OPENSSL_VERSION_NUMBER>=0x10002000L && !defined(LIBRESSL_VERSION_NUMBER)
     SSL_CONF_CTX *cctx;
     NAME_LIST *curr;
     char *cmd, *param;
