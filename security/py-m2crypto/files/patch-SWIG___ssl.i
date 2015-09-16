--- SWIG/_ssl.i.orig	2013-04-30 08:55:00 UTC
+++ SWIG/_ssl.i
@@ -48,8 +48,6 @@ extern const char *SSL_alert_desc_string
 %rename(ssl_get_alert_desc_v) SSL_alert_desc_string_long;
 extern const char *SSL_alert_desc_string_long(int);
 
-%rename(sslv3_method) SSLv3_method;
-extern SSL_METHOD *SSLv3_method(void);
 %rename(sslv23_method) SSLv23_method;
 extern SSL_METHOD *SSLv23_method(void);
 %rename(tlsv1_method) TLSv1_method;
