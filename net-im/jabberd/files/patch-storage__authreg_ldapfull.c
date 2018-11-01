--- storage/authreg_ldapfull.c.orig	2016-05-03 18:51:56 UTC
+++ storage/authreg_ldapfull.c
@@ -29,6 +29,8 @@
  * !!! this blocks for every auth.
  */
 
+#include <stdio.h>
+
 #define _XOPEN_SOURCE 500	// need this to get crypt()
 #include "c2s.h"
 
@@ -39,6 +41,7 @@
 
 #ifdef HAVE_SSL
 #include <openssl/rand.h>
+#include <openssl/evp.h>
 #endif
 
 #include <lber.h>
@@ -228,13 +231,18 @@ int _ldapfull_base64_decode( const char *src, const un
     int rc, tlen = 0;
     int i;
     unsigned char *text;
+#if OPENSSL_VERSION_NUMBER < 0x10100005L
     EVP_ENCODE_CTX EVP_ctx;
+#else
+    EVP_ENCODE_CTX *EVP_ctx;
+#endif
 
     text = (unsigned char *)malloc(((strlen(src)+3)/4 * 3) + 1);
     if (text == NULL) {
         return 0;
     }
 
+#if OPENSSL_VERSION_NUMBER < 0x10100005L
     EVP_DecodeInit(&EVP_ctx);
     rc = EVP_DecodeUpdate(&EVP_ctx, text, &i, (const unsigned char *)src, strlen(src));
     if (rc < 0) {
@@ -243,40 +251,69 @@ int _ldapfull_base64_decode( const char *src, const un
     }
     tlen+=i;
     EVP_DecodeFinal(&EVP_ctx, (unsigned char*)text, &i);
+#else
+    EVP_ctx = EVP_ENCODE_CTX_new();
+    EVP_DecodeInit(EVP_ctx);
+    rc = EVP_DecodeUpdate(EVP_ctx, text, &i, (const unsigned char *)src, strlen(src));
+    if (rc < 0) {
+        free(text);
+        EVP_ENCODE_CTX_free(EVP_ctx);
+        return 0;
+    }
+    tlen+=i;
+    EVP_DecodeFinal(EVP_ctx, (unsigned char*)text, &i);
+#endif
 
     *ret = text;
     if (rlen != NULL) {
         *rlen = tlen;
     }
 
+#if !(OPENSSL_VERSION_NUMBER < 0x10100005L)
+    EVP_ENCODE_CTX_free(EVP_ctx);
+#endif
     return 1;
 }
 
 static int _ldapfull_base64_encode( const unsigned char *src, int srclen, char **ret, int *rlen ) {
     int tlen = 0;
     unsigned char *text;
+#if OPENSSL_VERSION_NUMBER < 0x10100005L
     EVP_ENCODE_CTX EVP_ctx;
+#else
+    EVP_ENCODE_CTX *EVP_ctx;
+#endif
 
     text = (unsigned char *)malloc((srclen*4/3) + 1 );
     if (text == NULL) {
         return 0;
     }
 
+#if OPENSSL_VERSION_NUMBER < 0x10100005L
     EVP_EncodeInit(&EVP_ctx);
     EVP_EncodeUpdate(&EVP_ctx, text, &tlen, src, srclen);
     EVP_EncodeFinal(&EVP_ctx, text, &tlen);
+#else
+    EVP_ctx = EVP_ENCODE_CTX_new();
+    EVP_EncodeInit(EVP_ctx);
+    EVP_EncodeUpdate(EVP_ctx, text, &tlen, src, srclen);
+    EVP_EncodeFinal(EVP_ctx, text, &tlen);
+#endif
 
     *ret = (char*)text;
     if (rlen != NULL) {
         *rlen = tlen;
     }
 
+#if !(OPENSSL_VERSION_NUMBER < 0x10100005L)
+    EVP_ENCODE_CTX_free(EVP_ctx);
+#endif
     return 1;
 }
 
 int _ldapfull_chk_hashed(moddata_t data, const char *scheme, int salted, const char *hash, const char *passwd) {
     const unsigned char *bhash; // binary hash, will get it from base64
-    EVP_MD_CTX mdctx;
+    EVP_MD_CTX *mdctx;
     const EVP_MD *md;
     unsigned char digest[EVP_MAX_MD_SIZE];
     int bhlen, rc;
@@ -289,22 +326,32 @@ int _ldapfull_chk_hashed(moddata_t data, const char *s
         return 0;
     }
 
-    EVP_DigestInit(&mdctx, md);
-    EVP_DigestUpdate(&mdctx, passwd, strlen(passwd));
+#if OPENSSL_VERSION_NUMBER < 0x10100005L
+    mdctx = EVP_MD_CTX_create();
+#else
+    mdctx = EVP_MD_CTX_new();
+#endif
+    EVP_DigestInit(mdctx, md);
+    EVP_DigestUpdate(mdctx, passwd, strlen(passwd));
     if (salted) {
-        EVP_DigestUpdate(&mdctx, &bhash[EVP_MD_size(md)],
+        EVP_DigestUpdate(mdctx, &bhash[EVP_MD_size(md)],
                 bhlen - EVP_MD_size(md));
     }
-    EVP_DigestFinal(&mdctx, digest, NULL);
+    EVP_DigestFinal(mdctx, digest, NULL);
 
     rc = memcmp((char *)bhash, (char *)digest, EVP_MD_size(md));
     free((void*)bhash);
+#if OPENSSL_VERSION_NUMBER < 0x10100005L
+    EVP_MD_CTX_destroy(mdctx);
+#else
+    EVP_MD_CTX_free(mdctx);
+#endif
     return !rc;
 }
 
 int _ldapfull_set_hashed(moddata_t data, const char *scheme, const char *prefix, int saltlen, const char *passwd, char *buf, int buflen) {
     char *hash = 0; // base64 hash
-    EVP_MD_CTX mdctx;
+    EVP_MD_CTX *mdctx;
     const EVP_MD *md;
     unsigned char *digest;
     unsigned char *salt;
@@ -316,30 +363,48 @@ int _ldapfull_set_hashed(moddata_t data, const char *s
     if (!md) {
         return 0;
     }
-    EVP_DigestInit(&mdctx, md);
-    EVP_DigestUpdate(&mdctx, passwd, strlen(passwd));
+
+#if OPENSSL_VERSION_NUMBER < 0x10100005L
+    mdctx = EVP_MD_CTX_create();
+#else
+    mdctx = EVP_MD_CTX_new();
+#endif
+    EVP_DigestInit(mdctx, md);
+    EVP_DigestUpdate(mdctx, passwd, strlen(passwd));
     if (saltlen) {
         salt = (unsigned char *)malloc(saltlen);
         if( !salt ) {
-            EVP_MD_CTX_cleanup(&mdctx);
+#if OPENSSL_VERSION_NUMBER < 0x10100005L
+            EVP_MD_CTX_destroy(mdctx);
+#else
+            EVP_MD_CTX_free(mdctx);
+#endif
             return 0;
         }
         if( !RAND_bytes(salt,saltlen) ) {
-            EVP_MD_CTX_cleanup(&mdctx);
+#if OPENSSL_VERSION_NUMBER < 0x10100005L
+            EVP_MD_CTX_destroy(mdctx);
+#else
+            EVP_MD_CTX_free(mdctx);
+#endif
             free(salt);
             return 0;
         }
-        EVP_DigestUpdate(&mdctx, salt, saltlen);
+        EVP_DigestUpdate(mdctx, salt, saltlen);
     }
     digest = (unsigned char *)malloc(EVP_MD_size(md) + saltlen);
     if( !digest ) {
         if (saltlen) {
             free(salt);
         }
-        EVP_MD_CTX_cleanup(&mdctx);
+#if OPENSSL_VERSION_NUMBER < 0x10100005L
+        EVP_MD_CTX_destroy(mdctx);
+#else
+        EVP_MD_CTX_free(mdctx);
+#endif
         return 0;
     }
-    EVP_DigestFinal(&mdctx, digest, &dlen);
+    EVP_DigestFinal(mdctx, digest, &dlen);
 
     memcpy(digest+dlen,salt,saltlen);
     if (saltlen) {
@@ -352,6 +417,11 @@ int _ldapfull_set_hashed(moddata_t data, const char *s
     free(digest);
     if( !rc ) {
         free(hash);
+#if OPENSSL_VERSION_NUMBER < 0x10100005L
+        EVP_MD_CTX_destroy(mdctx);
+#else
+        EVP_MD_CTX_free(mdctx);
+#endif
         return 0;
     }
 
@@ -359,12 +429,22 @@ int _ldapfull_set_hashed(moddata_t data, const char *s
     if( hlen + plen >= buflen ) {
         log_write(data->ar->c2s->log,LOG_ERR,"_ldapfull_set_hashed: buffer is too short (%i bytes)",buflen);
         free(hash);
+#if OPENSSL_VERSION_NUMBER < 0x10100005L
+        EVP_MD_CTX_destroy(mdctx);
+#else
+        EVP_MD_CTX_free(mdctx);
+#endif
         return 0;
     }
     memcpy(buf,prefix,plen);
     memcpy(buf+plen,hash,hlen);
     buf[hlen+plen]='\0';
     free(hash);
+#if OPENSSL_VERSION_NUMBER < 0x10100005L
+    EVP_MD_CTX_destroy(mdctx);
+#else
+    EVP_MD_CTX_free(mdctx);
+#endif
 
     return 1;
 }
