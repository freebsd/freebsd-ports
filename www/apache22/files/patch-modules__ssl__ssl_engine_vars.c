--- modules/ssl/ssl_engine_vars.c.orig	2013-02-12 12:51:17.000000000 +0100
+++ modules/ssl/ssl_engine_vars.c	2015-02-28 10:54:21.257798164 +0100
@@ -832,7 +832,7 @@
 {
     char *result = "NULL";
 #ifdef OPENSSL_VERSION_NUMBER
-#if (OPENSSL_VERSION_NUMBER >= 0x00908000)
+#if (OPENSSL_VERSION_NUMBER >= 0x00908000) && !defined(OPENSSL_NO_COMP)
     SSL_SESSION *pSession = SSL_get_session(ssl);
 
     if (pSession) {
