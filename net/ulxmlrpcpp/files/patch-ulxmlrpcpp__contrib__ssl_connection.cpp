--- ulxmlrpcpp/contrib/ssl_connection.cpp.orig	2009-08-12 14:37:53 UTC
+++ ulxmlrpcpp/contrib/ssl_connection.cpp
@@ -40,6 +40,7 @@
 //STL
 #include <deque>
 #include <iostream>
+#include <cstring>
 
 #include <errno.h>
 
@@ -227,7 +228,11 @@ ULXR_API_IMPL(void) SSLConnection::initializeCTX()
 	if (ssl_ctx != 0)
     	    SSL_CTX_free(ssl_ctx);
 
+#if defined(OPENSSL_VERSION_NUMBER) && OPENSSL_VERSION_NUMBER >= 0x10000000L
+	const SSL_METHOD *meth = SSLv23_method();
+#else
 	SSL_METHOD *meth = SSLv23_method();
+#endif
 
 	ssl_ctx = SSL_CTX_new (meth);
 
