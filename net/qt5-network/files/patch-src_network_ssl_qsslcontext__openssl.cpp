--- src/network/ssl/qsslcontext_openssl.cpp.orig	2022-06-22 10:58:13 UTC
+++ src/network/ssl/qsslcontext_openssl.cpp
@@ -54,12 +54,14 @@
 
 QT_BEGIN_NAMESPACE
 
+#ifdef SSL_SECOP_PEER
 Q_GLOBAL_STATIC(bool, forceSecurityLevel)
 
 Q_NETWORK_EXPORT void qt_ForceTlsSecurityLevel()
 {
     *forceSecurityLevel() = true;
 }
+#endif //SSL_SECOP_PEER
 
 // defined in qsslsocket_openssl.cpp:
 extern int q_X509Callback(int ok, X509_STORE_CTX *ctx);
@@ -351,9 +353,11 @@ init_context:
         return;
     }
 
+#ifdef SSL_SECOP_PEER
     // A nasty hacked OpenSSL using a level that will make our auto-tests fail:
     if (q_SSL_CTX_get_security_level(sslContext->ctx) > 1 && *forceSecurityLevel())
         q_SSL_CTX_set_security_level(sslContext->ctx, 1);
+#endif //SSL_SECOP_PEER
 
     const long anyVersion =
 #if QT_CONFIG(dtls)
@@ -408,16 +412,28 @@ init_context:
         maxVersion = DTLS1_VERSION;
         break;
     case QSsl::DtlsV1_0OrLater:
+#ifdef DTLS_MAX_VERSION
         minVersion = DTLS1_VERSION;
         maxVersion = 0;
+#else
+        Q_UNREACHABLE();
+#endif // DTLS_MAX_VERSION
         break;
     case QSsl::DtlsV1_2:
+#ifdef DTLS1_2_VERSION
         minVersion = DTLS1_2_VERSION;
         maxVersion = DTLS1_2_VERSION;
+#else
+        Q_UNREACHABLE();
+#endif // DTLS1_2_VERSION
         break;
     case QSsl::DtlsV1_2OrLater:
+#if defined(DTLS1_2_VERSION)
         minVersion = DTLS1_2_VERSION;
         maxVersion = 0;
+#else
+        Q_UNREACHABLE();
+#endif // DTLS1_2_VERSION
         break;
     case QSsl::TlsV1_3OrLater:
 #ifdef TLS1_3_VERSION
@@ -722,6 +738,7 @@ void QSslContext::applyBackendConfig(QSslContext *sslC
     }
 #endif // ocsp
 
+#ifndef LIBRESSL_VERSION_NUMBER
     QSharedPointer<SSL_CONF_CTX> cctx(q_SSL_CONF_CTX_new(), &q_SSL_CONF_CTX_free);
     if (cctx) {
         q_SSL_CONF_CTX_set_ssl_ctx(cctx.data(), sslContext->ctx);
@@ -768,7 +785,9 @@ void QSslContext::applyBackendConfig(QSslContext *sslC
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
