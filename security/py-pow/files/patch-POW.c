--- POW.c.orig	2002-09-18 05:54:28.000000000 +0200
+++ POW.c	2007-12-20 21:31:49.000000000 +0100
@@ -47,8 +47,10 @@
 #include <openssl/err.h>
 #include <openssl/md5.h>
 #include <openssl/md2.h>
+#include <openssl/rsa.h>
 #include <openssl/sha.h>
 #include <openssl/hmac.h>
+#include <openssl/ripemd.h>
 
 #include <time.h>
 
@@ -304,54 +306,54 @@
    switch(cipher_type)
    {
 #ifndef NO_DES
-      case DES_ECB:           return EVP_des_ecb();
-      case DES_EDE:           return EVP_des_ede();
-      case DES_EDE3:          return EVP_des_ede3();
-      case DES_CFB:           return EVP_des_cfb();
-      case DES_EDE_CFB:       return EVP_des_ede_cfb();
-      case DES_EDE3_CFB:      return EVP_des_ede3_cfb();
-      case DES_OFB:           return EVP_des_ofb();
-      case DES_EDE_OFB:       return EVP_des_ede_ofb();
-      case DES_EDE3_OFB:      return EVP_des_ede3_ofb();
-      case DES_CBC:           return EVP_des_cbc();
-      case DES_EDE_CBC:       return EVP_des_ede_cbc();
-      case DES_EDE3_CBC:      return EVP_des_ede3_cbc();
-      case DESX_CBC:          return EVP_desx_cbc();
+      case DES_ECB:           return (EVP_CIPHER *) EVP_des_ecb();
+      case DES_EDE:           return (EVP_CIPHER *) EVP_des_ede();
+      case DES_EDE3:          return (EVP_CIPHER *) EVP_des_ede3();
+      case DES_CFB:           return (EVP_CIPHER *) EVP_des_cfb();
+      case DES_EDE_CFB:       return (EVP_CIPHER *) EVP_des_ede_cfb();
+      case DES_EDE3_CFB:      return (EVP_CIPHER *) EVP_des_ede3_cfb();
+      case DES_OFB:           return (EVP_CIPHER *) EVP_des_ofb();
+      case DES_EDE_OFB:       return (EVP_CIPHER *) EVP_des_ede_ofb();
+      case DES_EDE3_OFB:      return (EVP_CIPHER *) EVP_des_ede3_ofb();
+      case DES_CBC:           return (EVP_CIPHER *) EVP_des_cbc();
+      case DES_EDE_CBC:       return (EVP_CIPHER *) EVP_des_ede_cbc();
+      case DES_EDE3_CBC:      return (EVP_CIPHER *) EVP_des_ede3_cbc();
+      case DESX_CBC:          return (EVP_CIPHER *) EVP_desx_cbc();
 #endif
 #ifndef NO_RC4
-      case RC4:               return EVP_rc4();
-      case RC4_40:            return EVP_rc4_40();
+      case RC4:               return (EVP_CIPHER *) EVP_rc4();
+      case RC4_40:            return (EVP_CIPHER *) EVP_rc4_40();
 #endif
 #ifndef NO_IDEA
-      case IDEA_ECB:          return EVP_idea_ecb();
-      case IDEA_CFB:          return EVP_idea_cfb();
-      case IDEA_OFB:          return EVP_idea_ofb();
-      case IDEA_CBC:          return EVP_idea_cbc();
+      case IDEA_ECB:          return (EVP_CIPHER *) EVP_idea_ecb();
+      case IDEA_CFB:          return (EVP_CIPHER *) EVP_idea_cfb();
+      case IDEA_OFB:          return (EVP_CIPHER *) EVP_idea_ofb();
+      case IDEA_CBC:          return (EVP_CIPHER *) EVP_idea_cbc();
 #endif
 #ifndef NO_RC2
-      case RC2_ECB:           return EVP_rc2_ecb();
-      case RC2_CBC:           return EVP_rc2_cbc();
-      case RC2_40_CBC:        return EVP_rc2_40_cbc();
-      case RC2_CFB:           return EVP_rc2_cfb();
-      case RC2_OFB:           return EVP_rc2_ofb();
+      case RC2_ECB:           return (EVP_CIPHER *) EVP_rc2_ecb();
+      case RC2_CBC:           return (EVP_CIPHER *) EVP_rc2_cbc();
+      case RC2_40_CBC:        return (EVP_CIPHER *) EVP_rc2_40_cbc();
+      case RC2_CFB:           return (EVP_CIPHER *) EVP_rc2_cfb();
+      case RC2_OFB:           return (EVP_CIPHER *) EVP_rc2_ofb();
 #endif
 #ifndef NO_BF
-      case BF_ECB:            return EVP_bf_ecb();
-      case BF_CBC:            return EVP_bf_cbc();
-      case BF_CFB:            return EVP_bf_cfb();
-      case BF_OFB:            return EVP_bf_ofb();
+      case BF_ECB:            return (EVP_CIPHER *) EVP_bf_ecb();
+      case BF_CBC:            return (EVP_CIPHER *) EVP_bf_cbc();
+      case BF_CFB:            return (EVP_CIPHER *) EVP_bf_cfb();
+      case BF_OFB:            return (EVP_CIPHER *) EVP_bf_ofb();
 #endif
 #ifndef NO_CAST5
-      case CAST5_ECB:         return EVP_cast5_ecb();
-      case CAST5_CBC:         return EVP_cast5_cbc();
-      case CAST5_CFB:         return EVP_cast5_cfb();
-      case CAST5_OFB:         return EVP_cast5_ofb();
+      case CAST5_ECB:         return (EVP_CIPHER *) EVP_cast5_ecb();
+      case CAST5_CBC:         return (EVP_CIPHER *) EVP_cast5_cbc();
+      case CAST5_CFB:         return (EVP_CIPHER *) EVP_cast5_cfb();
+      case CAST5_OFB:         return (EVP_CIPHER *) EVP_cast5_ofb();
 #endif
 #ifndef NO_RC5_32_12_16
-      case RC5_32_12_16_CBC:  return EVP_rc5_32_12_16_cbc();
-      case RC5_32_12_16_CFB:  return EVP_rc5_32_12_16_cfb();
-      case RC5_32_12_16_ECB:  return EVP_rc5_32_12_16_ecb();
-      case RC5_32_12_16_OFB:  return EVP_rc5_32_12_16_ofb();
+      case RC5_32_12_16_CBC:  return (EVP_CIPHER *) EVP_rc5_32_12_16_cbc();
+      case RC5_32_12_16_CFB:  return (EVP_CIPHER *) EVP_rc5_32_12_16_cfb();
+      case RC5_32_12_16_ECB:  return (EVP_CIPHER *) EVP_rc5_32_12_16_ecb();
+      case RC5_32_12_16_OFB:  return (EVP_CIPHER *) EVP_rc5_32_12_16_ofb();
 #endif
       default:                return NULL;
    }
@@ -580,7 +582,7 @@
 X509_object_der_read(char *src, int len)
 {
    x509_object *self;
-   unsigned char *ptr = src;
+   const unsigned char *ptr = src;
 
    if ( !(self = PyObject_New( x509_object, &x509type ) ) )
       goto error;
@@ -2050,7 +2052,7 @@
 x509_crl_object_der_read(char *src, int len)
 {
    x509_crl_object *self;
-   unsigned char* ptr = src;
+   const unsigned char* ptr = src;
 
    if ( !(self = PyObject_New( x509_crl_object, &x509_crltype ) ) )
       goto error;
@@ -2435,7 +2437,7 @@
 X509_REVOKED_dup(X509_REVOKED *rev)
 {
    return((X509_REVOKED *)ASN1_dup((int (*)())i2d_X509_REVOKED,
-      (char *(*)())d2i_X509_REVOKED,(char *)rev));
+      (void *)d2i_X509_REVOKED,(char *)rev));
 }
 
 static PyObject *
@@ -4576,7 +4578,7 @@
 asymmetric_object_der_read(int key_type, char *src, int len)
 {
    asymmetric_object *self=NULL;
-   unsigned char *ptr = src;
+   const unsigned char *ptr = src;
 
    self = PyObject_New( asymmetric_object, &asymmetrictype );
    if (self == NULL)
@@ -5777,7 +5779,7 @@
 hmac_object_new(int digest_type, char *key, int key_len)
 {
    hmac_object *self=NULL;
-   EVP_MD *md=NULL;
+   const EVP_MD *md=NULL;
 
    self = PyObject_New( hmac_object, &hmactype );
    if (self == NULL)
