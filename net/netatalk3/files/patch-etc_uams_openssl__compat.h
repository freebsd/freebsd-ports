--- etc/uams/openssl_compat.h.orig	2022-02-28 13:32:06 UTC
+++ etc/uams/openssl_compat.h
@@ -11,7 +11,7 @@ http://www.gnu.org/licenses/old-licenses/gpl-2.0.txt
 #ifndef OPENSSL_COMPAT_H
 #define OPENSSL_COMPAT_H
 
-#if OPENSSL_VERSION_NUMBER < 0x10100000L || defined(LIBRESSL_VERSION_NUMBER)
+#if OPENSSL_VERSION_NUMBER < 0x10100000L || (defined(LIBRESSL_VERSION_NUMBER) && LIBRESSL_VERSION_NUMBER < 0x2070000fL)
 inline static int DH_set0_pqg(DH *dh, BIGNUM *p, BIGNUM *q, BIGNUM *g)
 {
    /* If the fields p and g in d are NULL, the corresponding input
