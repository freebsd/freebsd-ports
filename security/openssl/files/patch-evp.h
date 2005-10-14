--- crypto/evp/evp.h.orig	Thu Oct 13 17:24:41 2005
+++ crypto/evp/evp.h	Thu Oct 13 17:26:32 2005
@@ -132,7 +132,11 @@
 #define EVP_CAST5_KEY_SIZE		16
 #define EVP_RC5_32_12_16_KEY_SIZE	16
 */
+#ifdef OPENSSL_FIPS
 #define EVP_MAX_MD_SIZE			64	/* longest known SHA512 */
+#else
+#define EVP_MAX_MD_SIZE			(16+20)	/* The SSLv3 md5+sha1 type */
+#endif
 #define EVP_MAX_KEY_LENGTH		32
 #define EVP_MAX_IV_LENGTH		16
 #define EVP_MAX_BLOCK_LENGTH		32
