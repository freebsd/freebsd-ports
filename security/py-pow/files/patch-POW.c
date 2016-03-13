--- POW.c.orig	2002-09-18 03:54:28 UTC
+++ POW.c
@@ -46,9 +46,10 @@
 #include <openssl/evp.h>
 #include <openssl/err.h>
 #include <openssl/md5.h>
-#include <openssl/md2.h>
+#include <openssl/rsa.h>
 #include <openssl/sha.h>
 #include <openssl/hmac.h>
+#include <openssl/ripemd.h>
 
 #include <time.h>
 
@@ -124,7 +125,6 @@
 #define NO_DH
 
 // digests
-#define MD2_DIGEST            1
 #define MD5_DIGEST            2
 #define SHA_DIGEST            3
 #define SHA1_DIGEST           4
@@ -304,54 +304,54 @@ evp_cipher_factory(int cipher_type)
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
@@ -580,7 +580,7 @@ static x509_object *
 X509_object_der_read(char *src, int len)
 {
    x509_object *self;
-   unsigned char *ptr = src;
+   const unsigned char *ptr = src;
 
    if ( !(self = PyObject_New( x509_object, &x509type ) ) )
       goto error;
@@ -767,7 +767,6 @@ static char X509_object_sign__doc__[] = 
 "         signed, it should be one of the following:\n"
 "      </para>\n"
 "      <simplelist>\n"
-"         <member><constant>MD2_DIGEST</constant></member>\n"
 "         <member><constant>MD5_DIGEST</constant></member>\n"
 "         <member><constant>SHA_DIGEST</constant></member>\n"
 "         <member><constant>SHA1_DIGEST</constant></member>\n"
@@ -805,12 +804,6 @@ X509_object_sign(x509_object *self, PyOb
             { PyErr_SetString( SSLErrorObject, "could not sign certificate" ); goto error; }
          break;
       }
-      case MD2_DIGEST:
-      { 
-         if (!X509_sign(self->x509, pkey, EVP_md2() ) ) 
-            { PyErr_SetString( SSLErrorObject, "could not sign certificate" ); goto error; }
-         break;
-      }
       case SHA_DIGEST:
       { 
          if (!X509_sign(self->x509, pkey, EVP_sha() ) ) 
@@ -2050,7 +2043,7 @@ static x509_crl_object *
 x509_crl_object_der_read(char *src, int len)
 {
    x509_crl_object *self;
-   unsigned char* ptr = src;
+   const unsigned char* ptr = src;
 
    if ( !(self = PyObject_New( x509_crl_object, &x509_crltype ) ) )
       goto error;
@@ -2435,7 +2428,7 @@ static X509_REVOKED *
 X509_REVOKED_dup(X509_REVOKED *rev)
 {
    return((X509_REVOKED *)ASN1_dup((int (*)())i2d_X509_REVOKED,
-      (char *(*)())d2i_X509_REVOKED,(char *)rev));
+      (void *)d2i_X509_REVOKED,(char *)rev));
 }
 
 static PyObject *
@@ -2815,7 +2808,6 @@ static char x509_crl_object_sign__doc__[
 "         signed, it should be one of the following:\n"
 "      </para>\n"
 "      <simplelist>\n"
-"         <member><constant>MD2_DIGEST</constant></member>\n"
 "         <member><constant>MD5_DIGEST</constant></member>\n"
 "         <member><constant>SHA_DIGEST</constant></member>\n"
 "         <member><constant>SHA1_DIGEST</constant></member>\n"
@@ -2852,12 +2844,6 @@ x509_crl_object_sign(x509_crl_object *se
             { PyErr_SetString( SSLErrorObject, "could not sign certificate" ); goto error; }
          break;
       }
-      case MD2_DIGEST:
-      { 
-         if (!X509_CRL_sign(self->crl, pkey, EVP_md2() ) ) 
-            { PyErr_SetString( SSLErrorObject, "could not sign certificate" ); goto error; }
-         break;
-      }
       case SHA_DIGEST:
       { 
          if (!X509_CRL_sign(self->crl, pkey, EVP_sha() ) ) 
@@ -4576,7 +4562,7 @@ static asymmetric_object *
 asymmetric_object_der_read(int key_type, char *src, int len)
 {
    asymmetric_object *self=NULL;
-   unsigned char *ptr = src;
+   const unsigned char *ptr = src;
 
    self = PyObject_New( asymmetric_object, &asymmetrictype );
    if (self == NULL)
@@ -5031,7 +5017,6 @@ static char asymmetric_object_sign__doc_
 "         following:\n"
 "      </para>\n"
 "      <simplelist>\n"
-"         <member><constant>MD2_DIGEST</constant></member>\n"
 "         <member><constant>MD5_DIGEST</constant></member>\n"
 "         <member><constant>SHA_DIGEST</constant></member>\n"
 "         <member><constant>SHA1_DIGEST</constant></member>\n"
@@ -5063,8 +5048,6 @@ asymmetric_object_sign(asymmetric_object
 
    switch(digest_type)
    {
-      case MD2_DIGEST:
-         { digest_nid = NID_md2; digest_len = MD2_DIGEST_LENGTH; break; }
       case MD5_DIGEST:
          { digest_nid = NID_md5; digest_len = MD5_DIGEST_LENGTH; break; }
       case SHA_DIGEST:
@@ -5141,7 +5124,6 @@ static char asymmetric_object_verify__do
 "         following:\n"
 "      </para>\n"
 "      <simplelist>\n"
-"         <member><constant>MD2_DIGEST</constant></member>\n"
 "         <member><constant>MD5_DIGEST</constant></member>\n"
 "         <member><constant>SHA_DIGEST</constant></member>\n"
 "         <member><constant>SHA1_DIGEST</constant></member>\n"
@@ -5165,8 +5147,6 @@ asymmetric_object_verify(asymmetric_obje
 
    switch(digest_type)
    {
-      case MD2_DIGEST:
-         { digest_len = MD2_DIGEST_LENGTH; digest_nid = NID_md2; break; }
       case MD5_DIGEST:
          { digest_len = MD5_DIGEST_LENGTH; digest_nid = NID_md5; break; }
       case SHA_DIGEST:
@@ -5567,8 +5547,6 @@ digest_object_new(int digest_type)
 
    switch(digest_type)
    {
-      case MD2_DIGEST: 
-         { self->digest_type = MD2_DIGEST; EVP_DigestInit( &self->digest_ctx, EVP_md2() ); break; }
       case MD5_DIGEST: 
          { self->digest_type = MD5_DIGEST; EVP_DigestInit( &self->digest_ctx, EVP_md5() ); break; }
       case SHA_DIGEST: 
@@ -5777,7 +5755,7 @@ static hmac_object *
 hmac_object_new(int digest_type, char *key, int key_len)
 {
    hmac_object *self=NULL;
-   EVP_MD *md=NULL;
+   const EVP_MD *md=NULL;
 
    self = PyObject_New( hmac_object, &hmactype );
    if (self == NULL)
@@ -5785,8 +5763,6 @@ hmac_object_new(int digest_type, char *k
 
    switch(digest_type)
    {
-      case MD2_DIGEST: 
-         { md = EVP_md2(); break; }
       case MD5_DIGEST: 
          { md = EVP_md5(); break; }
       case SHA_DIGEST: 
@@ -6137,7 +6113,6 @@ static char pow_module_new_digest__doc__
 "         of digest to create and should be one of the following: \n"
 "      </para>\n"
 "      <simplelist>\n"
-"         <member><constant>MD2_DIGEST</constant></member>\n"
 "         <member><constant>MD5_DIGEST</constant></member>\n"
 "         <member><constant>SHA_DIGEST</constant></member>\n"
 "         <member><constant>SHA1_DIGEST</constant></member>\n"
@@ -6176,7 +6151,6 @@ static char pow_module_new_hmac__doc__[]
 "         string and <parameter>type</parameter> should be one of the following: \n"
 "      </para>\n"
 "      <simplelist>\n"
-"         <member><constant>MD2_DIGEST</constant></member>\n"
 "         <member><constant>MD5_DIGEST</constant></member>\n"
 "         <member><constant>SHA_DIGEST</constant></member>\n"
 "         <member><constant>SHA1_DIGEST</constant></member>\n"
@@ -7078,7 +7052,6 @@ init_POW(void)
 #endif
 
    // message digests
-   install_int_const( d, "MD2_DIGEST",                MD2_DIGEST );
    install_int_const( d, "MD5_DIGEST",                MD5_DIGEST );
    install_int_const( d, "SHA_DIGEST",                SHA_DIGEST );
    install_int_const( d, "SHA1_DIGEST",               SHA1_DIGEST );
