--- ulxmlrpcpp/contrib/ssl_connection.cpp.orig
+++ ulxmlrpcpp/contrib/ssl_connection.cpp
@@ -227,7 +227,11 @@
 	if (ssl_ctx != 0)
     	    SSL_CTX_free(ssl_ctx);
 
+#if defined(OPENSSL_VERSION_NUMBER) && OPENSSL_VERSION_NUMBER >= 0x10000000L
+	const SSL_METHOD *meth = SSLv23_method();
+#else
 	SSL_METHOD *meth = SSLv23_method();
+#endif
 
 	ssl_ctx = SSL_CTX_new (meth);
 
