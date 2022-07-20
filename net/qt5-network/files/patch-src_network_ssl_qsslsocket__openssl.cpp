--- src/network/ssl/qsslsocket_openssl.cpp.orig	2022-07-05 09:21:21 UTC
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
@@ -254,10 +260,8 @@ int q_ssl_sess_set_new_cb(SSL *ssl, SSL_SESSION *sessi
                                                                  QSslSocketBackendPrivate::s_indexForSSLExtraData));
     return socketPrivate->handleNewSessionTicket(ssl);
 }
-#endif // TLS1_3_VERSION
+#endif
 
-#endif // !OPENSSL_NO_PSK
-
 #if QT_CONFIG(ocsp)
 
 int qt_OCSP_status_server_callback(SSL *ssl, void *ocspRequest)
@@ -653,7 +657,7 @@ bool QSslSocketBackendPrivate::initSslContext()
     else if (mode == QSslSocket::SslServerMode)
         q_SSL_set_psk_server_callback(ssl, &q_ssl_psk_server_callback);
 
-#if OPENSSL_VERSION_NUMBER >= 0x10101006L
+#if OPENSSL_VERSION_NUMBER >= 0x10101006L && !defined(LIBRESSL_VERSION_NUMBER)
     // Set the client callback for TLSv1.3 PSK
     if (mode == QSslSocket::SslClientMode
         && QSslSocket::sslLibraryBuildVersionNumber() >= 0x10101006L) {
