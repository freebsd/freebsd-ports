--- src/context.c.orig	2014-01-29 20:43:33 UTC
+++ src/context.c
@@ -66,7 +66,9 @@ static int set_option_flag(const char *o
 static LSEC_SSL_METHOD* str2method(const char *method)
 {
   if (!strcmp(method, "sslv23"))  return SSLv23_method();
+#ifndef OPENSSL_NO_SSL3
   if (!strcmp(method, "sslv3"))   return SSLv3_method();
+#endif
   if (!strcmp(method, "tlsv1"))   return TLSv1_method();
 #if (OPENSSL_VERSION_NUMBER >= 0x1000100fL)
   if (!strcmp(method, "tlsv1_1")) return TLSv1_1_method();
