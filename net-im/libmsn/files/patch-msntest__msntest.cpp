--- msntest/msntest.cpp	2010/01/22 12:45:14	119
+++ msntest/msntest.cpp	2010/05/03 19:33:50	120
@@ -259,7 +259,13 @@
                     if(mySocketsSsl[i].isSSL && !mySocketsSsl[i].isConnected)
                     {
                         BIO *bio_socket_new;
-                        SSL_METHOD *meth=NULL;
+
+#if OPENSSL_VERSION_NUMBER >= 0x10000000L
+			const SSL_METHOD *meth=NULL;
+#else
+			SSL_METHOD *meth=NULL;
+#endif
+
                         meth=SSLv23_client_method();
                         SSLeay_add_ssl_algorithms();
                         mySocketsSsl[i].ctx = SSL_CTX_new(meth);
