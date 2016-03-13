--- pkcs12.c.orig	2016-02-29 00:16:50 UTC
+++ pkcs12.c
@@ -99,6 +99,10 @@
 #define _STACK STACK
 #endif
 
+#if defined(OPENSSL_VERSION_NUMBER) && OPENSSL_VERSION_NUMBER < 0x10000000L
+#define _STACK STACK
+#endif
+
 /* ================= P K C S 1 2    C O N V E R S I O N S ================ */
 /* Convert pem formatted certificate and private key into PKCS12
  * object suitable for importing to browsers.
