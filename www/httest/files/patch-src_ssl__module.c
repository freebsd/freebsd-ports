--- src/ssl_module.c.orig	2015-03-16 15:46:05 UTC
+++ src/ssl_module.c
@@ -349,7 +349,7 @@ static void ssl_message_trace(int write_
     case DTLS1_VERSION:
       str_version = "DTLS 1.0";
       break;
-#if (OPENSSL_VERSION_NUMBER >= 0x1000100fL)
+#if OPENSSL_VERSION_NUMBER >= 0x1000100fL && defined(DTLS1_BAD_VER)
     case DTLS1_BAD_VER:
       str_version = "DTLS 1.0 (bad)";
       break;
@@ -421,7 +421,7 @@ static void ssl_message_trace(int write_
       version == TLS1_1_VERSION ||
 #endif
       version == DTLS1_VERSION
-#if (OPENSSL_VERSION_NUMBER >= 0x1000100fL)
+#if OPENSSL_VERSION_NUMBER >= 0x1000100fL && defined(DTLS1_BAD_VER)
       || version == DTLS1_BAD_VER
 #endif
 	  ) {
@@ -740,10 +740,12 @@ static int worker_set_client_method(work
     config->meth = SSLv2_client_method();
   }
 #endif
+#ifndef OPENSSL_NO_SSL3
   else if (strcasecmp(sslstr, "SSL3") == 0) {
     is_ssl = 1;
     config->meth = SSLv3_client_method();
   }
+#endif
   else if (strcasecmp(sslstr, "TLS1") == 0) {
     is_ssl = 1;
     config->meth = TLSv1_client_method();
@@ -787,10 +789,12 @@ static int worker_set_server_method(work
     config->meth = SSLv2_server_method();
   }
 #endif
+#ifndef OPENSSL_NO_SSL3
   else if (strcasecmp(sslstr, "SSL3") == 0) {
     is_ssl = 1;
     config->meth = SSLv3_server_method();
   }
+#endif
   else if (strcasecmp(sslstr, "TLS1") == 0) {
     is_ssl = 1;
     config->meth = TLSv1_server_method();
