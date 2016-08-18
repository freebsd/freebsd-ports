--- src/_cffi_src/openssl/ec.py.orig	2016-06-04 17:06:01 UTC
+++ src/_cffi_src/openssl/ec.py
@@ -371,7 +371,8 @@ EC_GROUP *(*EC_GROUP_new_curve_GF2m)(
 static const long Cryptography_HAS_EC2M = 1;
 #endif
 
-#if defined(OPENSSL_NO_EC) || OPENSSL_VERSION_NUMBER < 0x1000200f || \
+#if defined(OPENSSL_NO_EC) || \
+    OPENSSL_VERSION_NUMBER < 0x1000200f && !defined(LIBRESSL_VERSION_NUMBER) || \
     defined(LIBRESSL_VERSION_NUMBER) && LIBRESSL_VERSION_NUMBER < 0x20020002L
 static const long Cryptography_HAS_EC_1_0_2 = 0;
 const char *(*EC_curve_nid2nist)(int) = NULL;
