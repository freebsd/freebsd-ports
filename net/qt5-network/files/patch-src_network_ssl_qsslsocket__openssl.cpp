--- src/network/ssl/qsslsocket_openssl.cpp.orig	2022-06-28 13:46:41 UTC
+++ src/network/ssl/qsslsocket_openssl.cpp
@@ -239,6 +239,12 @@ static int q_ssl_psk_use_session_callback(SSL *ssl, co
     return 1; // need to return 1 or else "the connection setup fails."
 }
 
+#endif // TLS1_3_VERSION
+
+#endif // !OPENSSL_NO_PSK
+
+#if (!defined(OPENSSL_NO_PSK) || defined(LIBRESSL_VERSION_NUMBER)) \
+	&& defined(TLS1_3_VERSION)
 int q_ssl_sess_set_new_cb(SSL *ssl, SSL_SESSION *session)
 {
     if (!ssl) {
@@ -254,9 +260,7 @@ int q_ssl_sess_set_new_cb(SSL *ssl, SSL_SESSION *sessi
                                                                  QSslSocketBackendPrivate::s_indexForSSLExtraData));
     return socketPrivate->handleNewSessionTicket(ssl);
 }
-#endif // TLS1_3_VERSION
-
-#endif // !OPENSSL_NO_PSK
+#endif
 
 #if QT_CONFIG(ocsp)
 
