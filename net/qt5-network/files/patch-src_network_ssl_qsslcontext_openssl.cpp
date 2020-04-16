--- src/network/ssl/qsslcontext_openssl.cpp.orig	2019-10-01 08:05:51 UTC
+++ src/network/ssl/qsslcontext_openssl.cpp
@@ -265,7 +265,7 @@ void QSslContext::applyBackendConfig(QSslContext *sslC
     }
 #endif // ocsp
 
-#if OPENSSL_VERSION_NUMBER >= 0x10002000L
+#if OPENSSL_VERSION_NUMBER >= 0x10002000L && !defined(LIBRESSL_VERSION_NUMBER)
     if (QSslSocket::sslLibraryVersionNumber() >= 0x10002000L) {
         QSharedPointer<SSL_CONF_CTX> cctx(q_SSL_CONF_CTX_new(), &q_SSL_CONF_CTX_free);
         if (cctx) {
