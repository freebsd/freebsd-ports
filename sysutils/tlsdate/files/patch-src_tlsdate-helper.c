--- src/tlsdate-helper.c.orig	2015-05-28 18:49:40 UTC
+++ src/tlsdate-helper.c
@@ -1133,10 +1133,12 @@ run_ssl (uint32_t *time_map, int time_is
   {
     verb ("V: using SSLv23_client_method()");
     ctx = SSL_CTX_new(SSLv23_client_method());
+#ifndef OPENSSL_NO_SSL3
   } else if (0 == strcmp("sslv3", protocol))
   {
     verb ("V: using SSLv3_client_method()");
     ctx = SSL_CTX_new(SSLv3_client_method());
+#endif
   } else if (0 == strcmp("tlsv1", protocol))
   {
     verb ("V: using TLSv1_client_method()");
