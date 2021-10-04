Patch from Gentoo: https://gitweb.gentoo.org/repo/gentoo.git/plain/dev-qt/qtnetwork/files/qtnetwork-5.15.1-libressl.patch
--- src/network/ssl/qsslsocket_openssl.cpp.orig	2020-10-27 08:02:11 UTC
+++ src/network/ssl/qsslsocket_openssl.cpp
@@ -238,7 +238,11 @@ static int q_ssl_psk_use_session_callback(SSL *ssl, co
 
     return 1; // need to return 1 or else "the connection setup fails."
 }
+#endif // TLS1_3_VERSION
 
+#endif // !OPENSSL_NO_PSK
+
+#ifdef TLS1_3_VERSION
 int q_ssl_sess_set_new_cb(SSL *ssl, SSL_SESSION *session)
 {
     if (!ssl) {
@@ -256,8 +260,6 @@ int q_ssl_sess_set_new_cb(SSL *ssl, SSL_SESSION *sessi
 }
 #endif // TLS1_3_VERSION
 
-#endif // !OPENSSL_NO_PSK
-
 #if QT_CONFIG(ocsp)
 
 int qt_OCSP_status_server_callback(SSL *ssl, void *ocspRequest)
@@ -653,7 +655,7 @@ bool QSslSocketBackendPrivate::initSslContext()
     else if (mode == QSslSocket::SslServerMode)
         q_SSL_set_psk_server_callback(ssl, &q_ssl_psk_server_callback);
 
-#if OPENSSL_VERSION_NUMBER >= 0x10101006L
+#if OPENSSL_VERSION_NUMBER >= 0x10101006L && !defined(LIBRESSL_VERSION_NUMBER)
     // Set the client callback for TLSv1.3 PSK
     if (mode == QSslSocket::SslClientMode
         && QSslSocket::sslLibraryBuildVersionNumber() >= 0x10101006L) {
