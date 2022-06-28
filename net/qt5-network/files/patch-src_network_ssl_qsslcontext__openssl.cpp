--- src/network/ssl/qsslcontext_openssl.cpp.orig	2022-06-28 10:17:59 UTC
+++ src/network/ssl/qsslcontext_openssl.cpp
@@ -356,11 +356,15 @@ init_context:
         q_SSL_CTX_set_security_level(sslContext->ctx, 1);
 
     const long anyVersion =
+#ifndef TLS_ANY_VERSION
+	    		    0x1000;
+#else
 #if QT_CONFIG(dtls)
                             isDtls ? DTLS_ANY_VERSION : TLS_ANY_VERSION;
 #else
                             TLS_ANY_VERSION;
 #endif // dtls
+#endif
     long minVersion = anyVersion;
     long maxVersion = anyVersion;
 
@@ -722,6 +726,7 @@ void QSslContext::applyBackendConfig(QSslContext *sslC
     }
 #endif // ocsp
 
+#ifndef LIBRESSL_VERSION_NUMBER
     QSharedPointer<SSL_CONF_CTX> cctx(q_SSL_CONF_CTX_new(), &q_SSL_CONF_CTX_free);
     if (cctx) {
         q_SSL_CONF_CTX_set_ssl_ctx(cctx.data(), sslContext->ctx);
@@ -768,7 +773,9 @@ void QSslContext::applyBackendConfig(QSslContext *sslC
             sslContext->errorStr = msgErrorSettingBackendConfig(QSslSocket::tr("SSL_CONF_finish() failed"));
             sslContext->errorCode = QSslError::UnspecifiedError;
         }
-    } else {
+    } else
+#endif // LIBRESSL_VERSION_NUMBER
+    {
         sslContext->errorStr = msgErrorSettingBackendConfig(QSslSocket::tr("SSL_CONF_CTX_new() failed"));
         sslContext->errorCode = QSslError::UnspecifiedError;
     }
