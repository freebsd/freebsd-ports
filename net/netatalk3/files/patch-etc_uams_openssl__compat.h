--- etc/uams/openssl_compat.h.orig	2016-06-06 11:21:51 UTC
+++ etc/uams/openssl_compat.h
@@ -11,7 +11,7 @@
 #ifndef OPENSSL_COMPAT_H
 #define OPENSSL_COMPAT_H
 
-#if OPENSSL_VERSION_NUMBER < 0x10100000L
+#if OPENSSL_VERSION_NUMBER < 0x10100000L || defined(LIBRESSL_VERSION_NUMBER)
 inline static int DH_set0_pqg(DH *dh, BIGNUM *p, BIGNUM *q, BIGNUM *g)
 {
    /* If the fields p and g in d are NULL, the corresponding input
