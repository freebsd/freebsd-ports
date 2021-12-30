--- include/mbedtls/config.h.orig	2021-12-15 13:47:54 UTC
+++ include/mbedtls/config.h
@@ -1946,7 +1946,7 @@
  *
  * Uncomment this to enable support for use_srtp extension.
  */
-//#define MBEDTLS_SSL_DTLS_SRTP
+#define MBEDTLS_SSL_DTLS_SRTP
 
 /**
  * \def MBEDTLS_SSL_DTLS_CLIENT_PORT_REUSE
@@ -2129,7 +2129,7 @@
  *
  * Uncomment this to enable pthread mutexes.
  */
-//#define MBEDTLS_THREADING_PTHREAD
+#define MBEDTLS_THREADING_PTHREAD
 
 /**
  * \def MBEDTLS_USE_PSA_CRYPTO
@@ -3452,7 +3452,7 @@
  *
  * Enable this layer to allow use of mutexes within mbed TLS
  */
-//#define MBEDTLS_THREADING_C
+#define MBEDTLS_THREADING_C
 
 /**
  * \def MBEDTLS_TIMING_C
