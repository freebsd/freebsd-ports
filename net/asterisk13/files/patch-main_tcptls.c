--- main/tcptls.c.orig	2017-04-12 21:06:16 UTC
+++ main/tcptls.c
@@ -400,13 +400,13 @@ static int tcptls_stream_close(void *cookie)
 					SSL_get_error(stream->ssl, res));
 			}
 
-#if defined(OPENSSL_VERSION_NUMBER) && OPENSSL_VERSION_NUMBER >= 0x10100000L
+#if defined(OPENSSL_VERSION_NUMBER) && OPENSSL_VERSION_NUMBER >= 0x10100000L && !defined(LIBRESSL_VERSION_NUMBER)
 			if (!SSL_is_server(stream->ssl)) {
 #else
 			if (!stream->ssl->server) {
 #endif
 				/* For client threads, ensure that the error stack is cleared */
-#if !defined(OPENSSL_VERSION_NUMBER) || OPENSSL_VERSION_NUMBER < 0x10100000L
+#if !defined(OPENSSL_VERSION_NUMBER) || OPENSSL_VERSION_NUMBER < 0x10100000L || defined(LIBRESSL_VERSION_NUMBER)
 #if defined(OPENSSL_VERSION_NUMBER) && OPENSSL_VERSION_NUMBER >= 0x10000000L
 				ERR_remove_thread_state(NULL);
 #else
