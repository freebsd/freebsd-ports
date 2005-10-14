--- crypto/hmac/hmac.h.orig	Thu Oct 13 17:27:32 2005
+++ crypto/hmac/hmac.h	Thu Oct 13 17:28:43 2005
@@ -64,7 +64,11 @@
 
 #include <openssl/evp.h>
 
+#ifdef OPENSSL_FIPS
 #define HMAC_MAX_MD_CBLOCK	128
+#else
+#define HMAC_MAX_MD_CBLOCK	64
+#endif
 
 #ifdef  __cplusplus
 extern "C" {
