--- WWW/Library/Implementation/HTTP.c.orig	2016-11-23 16:45:25 UTC
+++ WWW/Library/Implementation/HTTP.c
@@ -926,7 +926,7 @@ static int HTLoadHTTP(const char *arg,
 #elif SSLEAY_VERSION_NUMBER >= 0x0900
 #ifndef USE_NSS_COMPAT_INCL
 	if (!try_tls) {
-#if OPENSSL_VERSION_NUMBER >= 0x10100000L
+#if OPENSSL_VERSION_NUMBER >= 0x10100000L && !defined(LIBRESSL_VERSION_NUMBER)
 	    SSL_set_min_proto_version(handle, TLS1_1_VERSION);
 #else
 	    SSL_set_options(handle, SSL_OP_NO_TLSv1);
