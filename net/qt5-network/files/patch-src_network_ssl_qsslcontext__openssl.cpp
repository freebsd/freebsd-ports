--- src/network/ssl/qsslcontext_openssl.cpp.orig	2020-05-17 21:00:32 UTC
+++ src/network/ssl/qsslcontext_openssl.cpp
@@ -696,6 +696,7 @@ void QSslContext::applyBackendConfig(QSslContext *sslC
     }
 #endif // ocsp
 
+#if !defined(LIBRESSL_VERSION_NUMBER)
     QSharedPointer<SSL_CONF_CTX> cctx(q_SSL_CONF_CTX_new(), &q_SSL_CONF_CTX_free);
     if (cctx) {
         q_SSL_CONF_CTX_set_ssl_ctx(cctx.data(), sslContext->ctx);
@@ -746,6 +747,7 @@ void QSslContext::applyBackendConfig(QSslContext *sslC
         sslContext->errorStr = msgErrorSettingBackendConfig(QSslSocket::tr("SSL_CONF_CTX_new() failed"));
         sslContext->errorCode = QSslError::UnspecifiedError;
     }
+#endif
 }
 
 QT_END_NAMESPACE
