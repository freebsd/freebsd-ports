--- examples/nettle-openssl.c.orig	Fri Nov  8 16:05:20 2002
+++ examples/nettle-openssl.c	Thu May  1 12:52:10 2003
@@ -93,7 +93,7 @@
 openssl_des_set_key(void *ctx, unsigned length, const uint8_t *key)
 {
   assert(length == 8);
-  des_key_sched((char *) key, ctx);
+  des_key_sched((const_DES_cblock *)key, ctx);
 }
 
 #define DES_BLOCK_SIZE 8
@@ -105,7 +105,7 @@
   assert (!(length % DES_BLOCK_SIZE));
   while (length)
     {
-      des_ecb_encrypt((char *) src, (char *) dst, ctx, DES_ENCRYPT);
+      des_ecb_encrypt((const_DES_cblock *)src, (DES_cblock *)dst, ctx, DES_ENCRYPT);
       length -= DES_BLOCK_SIZE;
       dst += DES_BLOCK_SIZE;
       src += DES_BLOCK_SIZE;
@@ -119,7 +119,7 @@
   assert (!(length % DES_BLOCK_SIZE));
   while (length)
     {
-      des_ecb_encrypt((char *) src, (char *) dst, ctx, DES_DECRYPT);
+      des_ecb_encrypt((const_DES_cblock *) src, (DES_cblock *) dst, ctx, DES_DECRYPT);
       length -= DES_BLOCK_SIZE;
       dst += DES_BLOCK_SIZE;
       src += DES_BLOCK_SIZE;
