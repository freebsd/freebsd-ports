--- modules/ssl/ssl_engine_vars.c.orig	2013-02-12 11:51:17 UTC
+++ modules/ssl/ssl_engine_vars.c
@@ -832,7 +832,7 @@ static char *ssl_var_lookup_ssl_compress
 {
     char *result = "NULL";
 #ifdef OPENSSL_VERSION_NUMBER
-#if (OPENSSL_VERSION_NUMBER >= 0x00908000)
+#if (OPENSSL_VERSION_NUMBER >= 0x00908000) && !defined(OPENSSL_NO_COMP)
     SSL_SESSION *pSession = SSL_get_session(ssl);
 
     if (pSession) {
