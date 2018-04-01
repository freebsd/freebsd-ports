* Instead of using the SSL_CTRL_SET_CURVES macros which only exists in OpenSSL,
* call the SSL_CTX_set1_groups function, which exists in LibreSSL as well as in 
* OpenSSL and is what would be called through the macro 
*
--- src/network/ssl/qsslcontext_openssl.cpp.orig	2018-01-16 06:53:43 UTC
+++ src/network/ssl/qsslcontext_openssl.cpp
@@ -354,12 +354,18 @@ init_context:
 #if OPENSSL_VERSION_NUMBER >= 0x10002000L && !defined(OPENSSL_NO_EC)
         // Set the curves to be used
         if (q_SSLeay() >= 0x10002000L) {
+#if defined(LIBRESSL_VERSION_NUMBER)
+            if (!q_SSL_CTX_set1_groups(sslContext->ctx,
+                                       const_cast<int *>(reinterpret_cast<const int *>(qcurves.data())),
+                                       qcurves.size())) {
+#else // defined(LIBRESSL_VERSION_NUMBER)
             // SSL_CTX_ctrl wants a non-const pointer as last argument,
             // but let's avoid a copy into a temporary array
             if (!q_SSL_CTX_ctrl(sslContext->ctx,
                                 SSL_CTRL_SET_CURVES,
                                 qcurves.size(),
                                 const_cast<int *>(reinterpret_cast<const int *>(qcurves.data())))) {
+#endif // defined(LIBRESSL_VERSION_NUMBER)
                 sslContext->errorStr = msgErrorSettingEllipticCurves(QSslSocketBackendPrivate::getErrorsFromOpenSsl());
                 sslContext->errorCode = QSslError::UnspecifiedError;
             }
