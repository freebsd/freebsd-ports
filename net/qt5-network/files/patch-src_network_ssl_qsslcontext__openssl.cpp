* Instead of using the SSL_CTRL_SET_CURVES macros which only exists in OpenSSL,
* call the SSL_CTX_set1_curves functions as suggested by BoringSSL porting docs
* and which is the function in OpenSSL that is called through the replaced macro.
* LibreSSL has a SSL_CTX_set1_groups functions and provides a compat macro.
* Unfortunately, since Qt resolves the symbols at runtime, we cannot call through
* that macro and must instead explicitly call SSL_CTX_set1_groups if the library
* doesn't export a function called SSL_CTX_set1_curves, as in the case of LibreSSL.
*
--- src/network/ssl/qsslcontext_openssl.cpp.orig	2016-12-01 08:17:04 UTC
+++ src/network/ssl/qsslcontext_openssl.cpp
@@ -350,14 +350,24 @@ init_context:
 #if OPENSSL_VERSION_NUMBER >= 0x10002000L && !defined(OPENSSL_NO_EC)
         // Set the curves to be used
         if (q_SSLeay() >= 0x10002000L) {
-            // SSL_CTX_ctrl wants a non-const pointer as last argument,
-            // but let's avoid a copy into a temporary array
-            if (!q_SSL_CTX_ctrl(sslContext->ctx,
-                                SSL_CTRL_SET_CURVES,
-                                qcurves.size(),
-                                const_cast<int *>(reinterpret_cast<const int *>(qcurves.data())))) {
-                sslContext->errorStr = msgErrorSettingEllipticCurves(QSslSocketBackendPrivate::getErrorsFromOpenSsl());
-                sslContext->errorCode = QSslError::UnspecifiedError;
+            switch (q_SSL_CTX_set1_curves(sslContext->ctx,
+                                          const_cast<int *>(reinterpret_cast<const int *>(qcurves.data())),
+                                          qcurves.size())) {
+                case 1:
+                default:
+                    break;
+                case 0:
+                    sslContext->errorStr = msgErrorSettingEllipticCurves(QSslSocketBackendPrivate::getErrorsFromOpenSsl());
+                    sslContext->errorCode = QSslError::UnspecifiedError;
+                    break;
+                case -1:
+                    if (q_SSL_CTX_set1_groups(sslContext->ctx,
+                                              reinterpret_cast<const int *>(qcurves.data()),
+                                              qcurves.size()) < 1) {
+                        sslContext->errorStr = msgErrorSettingEllipticCurves(QSslSocketBackendPrivate::getErrorsFromOpenSsl());
+                        sslContext->errorCode = QSslError::UnspecifiedError;
+                    }
+                    break;
             }
         } else
 #endif // OPENSSL_VERSION_NUMBER >= 0x10002000L && !defined(OPENSSL_NO_EC)
