--- sslcls.c.orig	2015-01-24 11:15:22.000000000 +0100
+++ sslcls.c
@@ -55,6 +55,7 @@
 }
 #endif
 
+#if HAVE_SSLv3_client_method
 const SSL_METHOD *sycSSLv3_client_method(void) {
    const SSL_METHOD *result;
    Debug("SSLv3_client_method()");
@@ -62,7 +63,9 @@
    Debug1("SSLv3_client_method() -> %p", result);
    return result;
 }
+#endif
 
+#if HAVE_SSLv3_server_method
 const SSL_METHOD *sycSSLv3_server_method(void) {
    const SSL_METHOD *result;
    Debug("SSLv3_server_method()");
@@ -70,6 +73,7 @@
    Debug1("SSLv3_server_method() -> %p", result);
    return result;
 }
+#endif
 
 const SSL_METHOD *sycSSLv23_client_method(void) {
    const SSL_METHOD *result;

