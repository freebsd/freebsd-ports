--- saferpay/idphttp.cpp.orig	Wed Jan 10 15:23:12 2001
+++ saferpay/idphttp.cpp	Mon Jul 30 13:33:13 2001
@@ -368,7 +368,7 @@
 public:
 	SslConnection()
 	{
-		SSLeay_add_ssl_algorithms();
+		SSL_library_init();
 		SSL_load_error_strings();
 
 		ctx = SSL_CTX_new(SSLv23_method());
