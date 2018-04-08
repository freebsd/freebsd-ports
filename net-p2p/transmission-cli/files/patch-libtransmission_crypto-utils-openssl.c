--- libtransmission/crypto-utils-openssl.c.orig	2018-01-23 19:17:43 UTC
+++ libtransmission/crypto-utils-openssl.c
@@ -230,7 +230,7 @@ tr_rc4_process (tr_rc4_ctx_t   handle,
 ****
 ***/
 
-#if OPENSSL_VERSION_NUMBER < 0x10100000 || defined(LIBRESSL_VERSION_NUMBER)
+#if OPENSSL_VERSION_NUMBER < 0x10100000 || (defined(LIBRESSL_VERSION_NUMBER) && LIBRESSL_VERSION_NUMBER < 0x20700000)
 static inline int
 DH_set0_pqg (DH     * dh,
              BIGNUM * p,
