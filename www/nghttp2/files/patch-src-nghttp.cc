--- src/nghttp.cc.orig	2018-03-25 12:28:55 UTC
+++ src/nghttp.cc
@@ -680,7 +680,7 @@ int HttpClient::initiate_connection() {
       const auto &host_string =
           config.host_override.empty() ? host : config.host_override;
 
-#if (!defined(LIBRESSL_VERSION_NUMBER) &&                                      \
+#if (!(defined(LIBRESSL_VERSION_NUMBER) && LIBRESSL_VERSION_NUMBER < 0x20700000L) && \
      OPENSSL_VERSION_NUMBER >= 0x10002000L) ||                                 \
     defined(OPENSSL_IS_BORINGSSL)
       auto param = SSL_get0_param(ssl);
