--- ulxmlrpcpp/ulxr_ssl_connection.cpp.orig	2009-08-12 14:38:22 UTC
+++ ulxmlrpcpp/ulxr_ssl_connection.cpp
@@ -40,6 +40,7 @@
 #include <openssl/err.h>
 #include <ulxmlrpcpp/ulxr_ssl_connection.h>
 #include <ulxmlrpcpp/ulxr_except.h>
+#include <cstring>
 
 
 static int s_server_session_id_context      = 1;
@@ -95,7 +96,11 @@ ULXR_API_IMPL(void)
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
