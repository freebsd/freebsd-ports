--- socket.c.orig	2018-12-30 11:43:19.042365000 -0600
+++ socket.c	2018-12-30 12:46:39.062201000 -0600
@@ -910,7 +910,7 @@
 	_ssl_context[sock] = NULL;
 	if(myproto) {
 		if(!strcasecmp("ssl2",myproto)) {
-#if HAVE_DECL_SSLV2_CLIENT_METHOD + 0 > 0
+#if (HAVE_DECL_SSLV2_CLIENT_METHOD + 0 > 0) && !defined(OPENSSL_NO_SSL2)
 			_ctx[sock] = SSL_CTX_new(SSLv2_client_method());
 #else
 			report(stderr, GT_("Your OpenSSL version does not support SSLv2.\n"));
@@ -918,7 +918,7 @@
 #endif
 			avoid_ssl_versions &= ~SSL_OP_NO_SSLv2;
 		} else if(!strcasecmp("ssl3",myproto)) {
-#if HAVE_DECL_SSLV3_CLIENT_METHOD + 0 > 0
+#if (HAVE_DECL_SSLV3_CLIENT_METHOD + 0 > 0) && !defined(OPENSSL_NO_SSL3_METHOD)
 			_ctx[sock] = SSL_CTX_new(SSLv3_client_method());
 #else
 			report(stderr, GT_("Your OpenSSL version does not support SSLv3.\n"));
