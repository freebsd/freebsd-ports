* check macro is defined instead of version, LibreSSL < 2.5 doesn't have SSL_CTRL_GET_SERVER_TMP_KEY
*
--- src/network/ssl/qsslsocket_openssl.cpp.orig	2016-12-01 08:17:04 UTC
+++ src/network/ssl/qsslsocket_openssl.cpp
@@ -1587,13 +1587,13 @@ void QSslSocketBackendPrivate::continueH
     }
 #endif // OPENSSL_VERSION_NUMBER >= 0x1000100fL ...
 
-#if OPENSSL_VERSION_NUMBER >= 0x10002000L
+#if defined(SSL_CTRL_GET_SERVER_TMP_KEY)
     if (q_SSLeay() >= 0x10002000L && mode == QSslSocket::SslClientMode) {
         EVP_PKEY *key;
         if (q_SSL_get_server_tmp_key(ssl, &key))
             configuration.ephemeralServerKey = QSslKey(key, QSsl::PublicKey);
     }
-#endif // OPENSSL_VERSION_NUMBER >= 0x10002000L ...
+#endif // defined(SSL_CTRL_GET_SERVER_TMP_KEY)
 
     connectionEncrypted = true;
     emit q->encrypted();
