--- src/rtc_base/openssl_adapter.cc.orig	2024-11-16 05:27:29 UTC
+++ src/rtc_base/openssl_adapter.cc
@@ -176,7 +176,9 @@ bool OpenSSLAdapter::InitializeSSL() {
   // Loading the error strings crashes mac_asan.  Omit this debugging aid there.
   SSL_load_error_strings();
 #endif
+#if defined(OPENSSL_VERSION_MAJOR) && (OPENSSL_VERSION_MAJOR < 3)
   ERR_load_BIO_strings();
+#endif
   OpenSSL_add_all_algorithms();
   RAND_poll();
   return true;
