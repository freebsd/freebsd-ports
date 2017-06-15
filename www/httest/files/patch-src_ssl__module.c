--- src/ssl_module.c.orig	2016-12-28 15:28:18 UTC
+++ src/ssl_module.c
@@ -350,7 +350,7 @@ static void ssl_message_trace(int write_
     case DTLS1_VERSION:
       str_version = "DTLS 1.0";
       break;
-#if (OPENSSL_VERSION_NUMBER >= 0x1000100fL)
+#if OPENSSL_VERSION_NUMBER >= 0x1000100fL && defined(DTLS1_BAD_VER)
     case DTLS1_BAD_VER:
       str_version = "DTLS 1.0 (bad)";
       break;
@@ -422,7 +422,7 @@ static void ssl_message_trace(int write_
       version == TLS1_1_VERSION ||
 #endif
       version == DTLS1_VERSION
-#if (OPENSSL_VERSION_NUMBER >= 0x1000100fL)
+#if OPENSSL_VERSION_NUMBER >= 0x1000100fL && defined(DTLS1_BAD_VER)
       || version == DTLS1_BAD_VER
 #endif
     ) {
@@ -743,7 +743,7 @@ static int worker_set_client_method(work
   }
 #endif
 #endif
-#ifndef OPENSSL_NO_SSL3_METHOD
+#ifndef OPENSSL_NO_SSL3
   else if (strcasecmp(sslstr, "SSL3") == 0) {
     is_ssl = 1;
     config->meth = SSLv3_client_method();
@@ -794,7 +794,7 @@ static int worker_set_server_method(work
   }
 #endif
 #endif
-#ifndef OPENSSL_NO_SSL3_METHOD
+#ifndef OPENSSL_NO_SSL3
   else if (strcasecmp(sslstr, "SSL3") == 0) {
     is_ssl = 1;
     config->meth = SSLv3_server_method();
