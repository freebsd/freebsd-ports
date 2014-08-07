--- pkcs12.c.orig
+++ pkcs12.c
@@ -95,6 +95,10 @@
 #define SMIME_INTERNALS  /* we want also our internal helper functions */
 #include "smimeutil.h"
 
+#if defined(OPENSSL_VERSION_NUMBER) && OPENSSL_VERSION_NUMBER < 0x10000000L
+#define _STACK STACK
+#endif
+
 /* ================= P K C S 1 2    C O N V E R S I O N S ================ */
 /* Convert pem formatted certificate and private key into PKCS12
  * object suitable for importing to browsers.
