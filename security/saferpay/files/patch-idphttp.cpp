--- saferpay/idphttp.cpp.orig	Wed Feb 19 10:57:14 2003
+++ saferpay/idphttp.cpp	Wed Feb 19 10:58:07 2003
@@ -374,7 +374,7 @@
 public:
 	SslConnection()
 	{
-		SSLeay_add_ssl_algorithms();
+		SSL_library_init();
 		SSL_load_error_strings();
 
 		ctx = SSL_CTX_new(SSLv23_method());
