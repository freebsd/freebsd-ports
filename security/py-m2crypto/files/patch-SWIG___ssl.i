--- SWIG/_ssl.i.orig	2015-10-13 14:34:30 UTC
+++ SWIG/_ssl.i
@@ -52,10 +52,6 @@ extern const char *SSL_alert_desc_string
 %rename(ssl_get_alert_desc_v) SSL_alert_desc_string_long;
 extern const char *SSL_alert_desc_string_long(int);
 
-%rename(sslv2_method) SSLv2_method;
-extern SSL_METHOD *SSLv2_method(void);
-%rename(sslv3_method) SSLv3_method;
-extern SSL_METHOD *SSLv3_method(void);
 %rename(sslv23_method) SSLv23_method;
 extern SSL_METHOD *SSLv23_method(void);
 %rename(tlsv1_method) TLSv1_method;
