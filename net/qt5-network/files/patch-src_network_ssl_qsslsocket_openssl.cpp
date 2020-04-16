--- src/network/ssl/qsslsocket_openssl.cpp.orig	2019-10-01 08:09:52 UTC
+++ src/network/ssl/qsslsocket_openssl.cpp
@@ -604,7 +604,7 @@ bool QSslSocketBackendPrivate::initSslContext()
             q_SSL_set_psk_server_callback(ssl, &q_ssl_psk_server_callback);
     }
 #endif
-#if OPENSSL_VERSION_NUMBER >= 0x10101006L
+#if OPENSSL_VERSION_NUMBER >= 0x10101006L && !defined(LIBRESSL_VERSION_NUMBER)
     // Set the client callback for TLSv1.3 PSK
     if (mode == QSslSocket::SslClientMode
         && QSslSocket::sslLibraryBuildVersionNumber() >= 0x10101006L) {
