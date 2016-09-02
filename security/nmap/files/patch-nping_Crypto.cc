--- nping/Crypto.cc.orig	2016-08-01 09:34:56 UTC
+++ nping/Crypto.cc
@@ -178,7 +178,7 @@ int Crypto::aes128_cbc_encrypt(u8 *inbuf
   #ifdef HAVE_OPENSSL
     if( o.doCrypto() ){
         int flen=0, flen2=0;
-        #if OPENSSL_VERSION_NUMBER < 0x10100000L
+        #if OPENSSL_VERSION_NUMBER < 0x10100000L || defined(LIBRESSL_VERSION_NUMBER)
           EVP_CIPHER_CTX ctx;
           EVP_CIPHER_CTX_init(&ctx);
           EVP_CIPHER_CTX_set_padding(&ctx, 0);
@@ -231,7 +231,7 @@ int Crypto::aes128_cbc_decrypt(u8 *inbuf
   #ifdef HAVE_OPENSSL
     if( o.doCrypto() ){
         int flen1=0, flen2=0;
-        #if OPENSSL_VERSION_NUMBER < 0x10100000L
+        #if OPENSSL_VERSION_NUMBER < 0x10100000L || defined(LIBRESSL_VERSION_NUMBER)
           EVP_CIPHER_CTX ctx;
           EVP_CIPHER_CTX_init(&ctx);
           EVP_CIPHER_CTX_set_padding(&ctx, 0);
@@ -286,7 +286,7 @@ int Crypto::aes128_cbc_decrypt(u8 *inbuf
             //ERR_free_strings();
             //ERR_pop_to_mark();
         }
-        #if OPENSSL_VERSION_NUMBER < 0x10100000L
+        #if OPENSSL_VERSION_NUMBER < 0x10100000L || defined(LIBRESSL_VERSION_NUMBER)
           EVP_CIPHER_CTX_cleanup(&ctx);
         #else
           EVP_CIPHER_CTX_reset(ctx);
@@ -327,7 +327,7 @@ u8 *Crypto::deriveKey(const u8 *from, si
         static u8 hash[MAX(SHA256_HASH_LEN, EVP_MAX_MD_SIZE)];
         static u8 next[MAX(SHA256_HASH_LEN, EVP_MAX_MD_SIZE)];
         unsigned int lastlen;
-      #if OPENSSL_VERSION_NUMBER < 0x10100000L
+      #if OPENSSL_VERSION_NUMBER < 0x10100000L || defined(LIBRESSL_VERSION_NUMBER)
         EVP_MD_CTX ctx;
         EVP_MD_CTX_init(&ctx);
 
