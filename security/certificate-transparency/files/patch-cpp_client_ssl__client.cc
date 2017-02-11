--- cpp/client/ssl_client.cc.orig	2016-10-14 17:11:57 UTC
+++ cpp/client/ssl_client.cc
@@ -88,7 +88,7 @@ SSLClient::SSLClient(const string& serve
 
   SSL_CTX_set_cert_verify_callback(ctx_.get(), &VerifyCallback, &verify_args_);
 
-#if OPENSSL_VERSION_NUMBER >= 0x10002000L
+#if OPENSSL_VERSION_NUMBER >= 0x10002000L && !defined(LIBRESSL_VERSION_NUMBER)
   SSL_CTX_add_client_custom_ext(ctx_.get(), CT_EXTENSION_TYPE, NULL, NULL,
                                 NULL, ExtensionCallback, &verify_args_);
 #else
