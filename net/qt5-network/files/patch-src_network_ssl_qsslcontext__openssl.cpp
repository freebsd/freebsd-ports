Patch from Gentoo: https://gitweb.gentoo.org/repo/gentoo.git/plain/dev-qt/qtnetwork/files/qtnetwork-5.15.1-libressl.patch
--- src/network/ssl/qsslcontext_openssl.cpp.orig	2020-09-02 10:15:07 UTC
+++ src/network/ssl/qsslcontext_openssl.cpp
@@ -397,16 +397,28 @@ init_context:
         maxVersion = DTLS1_VERSION;
         break;
     case QSsl::DtlsV1_0OrLater:
+#ifdef DTLS_MAX_VERSION
         minVersion = DTLS1_VERSION;
         maxVersion = DTLS_MAX_VERSION;
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
+#if defined(DTLS1_2_VERSION) && defined(DTLS_MAX_VERSION)
         minVersion = DTLS1_2_VERSION;
         maxVersion = DTLS_MAX_VERSION;
+#else
+        Q_UNREACHABLE();
+#endif // DTLS1_2_VERSION && DTLS_MAX_VERSION
         break;
     case QSsl::TlsV1_3OrLater:
 #ifdef TLS1_3_VERSION
@@ -711,6 +723,7 @@ void QSslContext::applyBackendConfig(QSslContext *sslC
     }
 #endif // ocsp
 
+#ifndef LIBRESSL_VERSION_NUMBER
     QSharedPointer<SSL_CONF_CTX> cctx(q_SSL_CONF_CTX_new(), &q_SSL_CONF_CTX_free);
     if (cctx) {
         q_SSL_CONF_CTX_set_ssl_ctx(cctx.data(), sslContext->ctx);
@@ -757,7 +770,9 @@ void QSslContext::applyBackendConfig(QSslContext *sslC
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
