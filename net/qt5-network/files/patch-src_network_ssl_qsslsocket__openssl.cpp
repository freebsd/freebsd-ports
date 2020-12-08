Patch from Gentoo: https://gitweb.gentoo.org/repo/gentoo.git/plain/dev-qt/qtnetwork/files/qtnetwork-5.15.1-libressl.patch
--- src/network/ssl/qsslsocket_openssl.cpp.orig	2020-09-02 10:15:07 UTC
+++ src/network/ssl/qsslsocket_openssl.cpp
@@ -653,7 +653,7 @@ bool QSslSocketBackendPrivate::initSslContext()
     else if (mode == QSslSocket::SslServerMode)
         q_SSL_set_psk_server_callback(ssl, &q_ssl_psk_server_callback);
 
-#if OPENSSL_VERSION_NUMBER >= 0x10101006L
+#if OPENSSL_VERSION_NUMBER >= 0x10101006L && !defined(LIBRESSL_VERSION_NUMBER)
     // Set the client callback for TLSv1.3 PSK
     if (mode == QSslSocket::SslClientMode
         && QSslSocket::sslLibraryBuildVersionNumber() >= 0x10101006L) {
