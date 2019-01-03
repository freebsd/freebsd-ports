--- etc/uams/openssl_compat.h.orig	2019-01-03 18:36:43.123024000 +0000
+++ etc/uams/openssl_compat.h	2019-01-03 18:37:02.918877000 +0000
@@ -11,7 +11,7 @@ http://www.gnu.org/licenses/old-licenses
 #ifndef OPENSSL_COMPAT_H
 #define OPENSSL_COMPAT_H
 
-#if OPENSSL_VERSION_NUMBER < 0x10100000L || defined(LIBRESSL_VERSION_NUMBER)
+#if OPENSSL_VERSION_NUMBER < 0x10100000L || (defined(LIBRESSL_VERSION_NUMBER) && LIBRESSL_VERSION_NUMBER < 0x2070000fL)
 inline static int DH_set0_pqg(DH *dh, BIGNUM *p, BIGNUM *q, BIGNUM *g)
 {
    /* If the fields p and g in d are NULL, the corresponding input
