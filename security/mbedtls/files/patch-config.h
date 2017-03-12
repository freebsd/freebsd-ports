--- include/mbedtls/config.h.orig	2017-03-08 15:33:04 UTC
+++ include/mbedtls/config.h
@@ -1285,7 +1285,7 @@
  *
  * Uncomment this to enable pthread mutexes.
  */
-//#define MBEDTLS_THREADING_PTHREAD
+#define MBEDTLS_THREADING_PTHREAD
 
 /**
  * \def MBEDTLS_VERSION_FEATURES
@@ -2322,7 +2322,7 @@
  *
  * Enable this layer to allow use of mutexes within mbed TLS
  */
-//#define MBEDTLS_THREADING_C
+#define MBEDTLS_THREADING_C
 
 /**
  * \def MBEDTLS_TIMING_C
