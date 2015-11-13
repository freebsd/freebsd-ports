--- src/_cffi_src/openssl/ec.py.orig	2015-09-27 13:51:07 UTC
+++ src/_cffi_src/openssl/ec.py
@@ -396,7 +396,8 @@ EC_GROUP *(*EC_GROUP_new_curve_GF2m)(
 static const long Cryptography_HAS_EC2M = 1;
 #endif
 
-#if defined(OPENSSL_NO_EC) || OPENSSL_VERSION_NUMBER < 0x1000200f || \
+#if defined(OPENSSL_NO_EC) || \
+    OPENSSL_VERSION_NUMBER < 0x1000200f && !defined(LIBRESSL_VERSION_NUMBER) || \
     defined(LIBRESSL_VERSION_NUMBER) && LIBRESSL_VERSION_NUMBER < 0x20020002L
 static const long Cryptography_HAS_EC_1_0_2 = 0;
 const char *(*EC_curve_nid2nist)(int) = NULL;
