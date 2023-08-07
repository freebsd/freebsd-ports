--- src/drivers/openssl/openssl_hsm_pkey.c.orig	2023-06-27 08:58:28.478388000 +0200
+++ src/drivers/openssl/openssl_hsm_pkey.c	2023-06-27 13:17:52.668464000 +0200
@@ -443,8 +443,11 @@
             } break;
 #ifdef ENABLE_ECDSA
         case EVP_PKEY_EC: {
-# if OPENSSL_VERSION_NUMBER < 0x1010000fL
+# if OPENSSL_VERSION_NUMBER >= 0x30000000L
             ret = PEM_write_bio_ECPrivateKey(bp, 
+                EVP_PKEY_get1_EC_KEY(x), enc, (unsigned char *) kstr, klen, cb, u);
+# elif OPENSSL_VERSION_NUMBER < 0x1010000fL
+            ret = PEM_write_bio_ECPrivateKey(bp, 
                 x->pkey.ec, enc, (unsigned char *) kstr, klen, cb, u);
 # else
             ret = PEM_write_bio_ECPrivateKey(bp, 
@@ -480,7 +483,9 @@
 
         case EVP_PKEY_RSA: {
             RSA *rsa = NULL;
-#if OPENSSL_VERSION_NUMBER >= 0x1010000fL
+#if OPENSSL_VERSION_NUMBER >= 0x30000000L
+            if (((rsa = EVP_PKEY_get1_RSA(kVal)) == NULL) ||
+#elif OPENSSL_VERSION_NUMBER >= 0x1010000fL
             if (((rsa = EVP_PKEY_get0_RSA(kVal)) == NULL) ||
 #else
             if (((rsa = (RSA *)EVP_PKEY_get0(kVal)) == NULL) ||
@@ -492,7 +497,9 @@
 
         case EVP_PKEY_DH: {
             DH *dh = NULL;
-#if OPENSSL_VERSION_NUMBER >= 0x1010000fL
+#if OPENSSL_VERSION_NUMBER >= 0x30000000L
+            if ( ((dh = EVP_PKEY_get1_DH(kVal)) == NULL) ||
+#elif OPENSSL_VERSION_NUMBER >= 0x1010000fL
             if ( ((dh = EVP_PKEY_get0_DH(kVal)) == NULL) ||
 #else
             if ( ((dh = (DH *)EVP_PKEY_get0(kVal)) == NULL) ||
@@ -505,7 +512,9 @@
 #ifdef ENABLE_ECDSA
         case EVP_PKEY_EC: {
             EC_KEY * ec = NULL;
-#if OPENSSL_VERSION_NUMBER >= 0x1010000fL
+#if OPENSSL_VERSION_NUMBER >= 0x30000000L
+            if (((ec = EVP_PKEY_get1_EC_KEY(kVal)) == NULL) ||
+#elif OPENSSL_VERSION_NUMBER >= 0x1010000fL
             if (((ec = EVP_PKEY_get0_EC_KEY(kVal)) == NULL) ||
 #else
             if (((ec = (EC_KEY *)EVP_PKEY_get0(kVal)) == NULL) ||
@@ -519,7 +528,9 @@
 #ifdef ENABLE_DSA
         case EVP_PKEY_DSA: {
             DSA *dsa = NULL;
-#if OPENSSL_VERSION_NUMBER >= 0x1010000fL
+#if OPENSSL_VERSION_NUMBER >= 0x30000000L
+            if ( ((dsa = EVP_PKEY_get1_DSA(kVal)) == NULL) ||
+#elif OPENSSL_VERSION_NUMBER >= 0x1010000fL
             if ( ((dsa = EVP_PKEY_get0_DSA(kVal)) == NULL) ||
 #else
             if ( ((dsa = (DSA *)EVP_PKEY_get0(kVal)) == NULL) ||
