--- ulxmlrpcpp/ulxr_ssl_connection.cpp.orig
+++ ulxmlrpcpp/ulxr_ssl_connection.cpp
@@ -95,7 +95,11 @@
 ULXR_API_IMPL(void) SSLConnection::initializeCTX()
 {
   ULXR_TRACE(ULXR_PCHAR("initializeCTX"));
+#if defined(OPENSSL_VERSION_NUMBER) && OPENSSL_VERSION_NUMBER >= 0x10000000L
+  const SSL_METHOD *meth = SSLv23_method();
+#else
   SSL_METHOD *meth = SSLv23_method();
+#endif
   ssl_ctx = SSL_CTX_new (meth);
   if (!ssl_ctx)
   {
