--- socket.c.orig	2013-04-23 20:00:45 UTC
+++ socket.c
@@ -907,14 +907,19 @@ int SSLOpen(int sock, char *mycert, char
 	_ssl_context[sock] = NULL;
 	if(myproto) {
 		if(!strcasecmp("ssl2",myproto)) {
-#if HAVE_DECL_SSLV2_CLIENT_METHOD + 0 > 0
+#ifndef OPENSSL_NO_SSL2
 			_ctx[sock] = SSL_CTX_new(SSLv2_client_method());
 #else
-			report(stderr, GT_("Your operating system does not support SSLv2.\n"));
+			report(stderr, GT_("Your OpenSSL version does not support SSLv2.\n"));
 			return -1;
 #endif
 		} else if(!strcasecmp("ssl3",myproto)) {
+#ifndef OPENSSL_NO_SSL3_METHOD
 			_ctx[sock] = SSL_CTX_new(SSLv3_client_method());
+#else
+			report(stderr, GT_("Your OpenSSL version does not support SSLv3.\n"));
+			return -1;
+#endif
 		} else if(!strcasecmp("tls1",myproto)) {
 			_ctx[sock] = SSL_CTX_new(TLSv1_client_method());
 		} else if (!strcasecmp("ssl23",myproto)) {
