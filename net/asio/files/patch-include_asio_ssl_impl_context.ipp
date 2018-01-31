--- include/asio/ssl/impl/context.ipp.orig	2015-03-23 20:28:30 UTC
+++ include/asio/ssl/impl/context.ipp
@@ -88,6 +88,14 @@ context::context(context::method m)
     handle_ = ::SSL_CTX_new(::SSLv2_server_method());
     break;
 #endif // defined(OPENSSL_NO_SSL2)
+#if defined(OPENSSL_NO_SSL3)
+  case context::sslv3:
+  case context::sslv3_client:
+  case context::sslv3_server:
+    asio::detail::throw_error(
+        asio::error::invalid_argument, "context");
+    break;
+#else // defined(OPENSSL_NO_SSL3)
   case context::sslv3:
     handle_ = ::SSL_CTX_new(::SSLv3_method());
     break;
@@ -97,6 +105,7 @@ context::context(context::method m)
   case context::sslv3_server:
     handle_ = ::SSL_CTX_new(::SSLv3_server_method());
     break;
+#endif // defined(OPENSSL_NO_SSL3)
   case context::tlsv1:
     handle_ = ::SSL_CTX_new(::TLSv1_method());
     break;
