--- cipher/salsa20.c.orig	2016-03-23 16:34:00 UTC
+++ cipher/salsa20.c
@@ -485,7 +485,8 @@ salsa20r12_encrypt_stream (void *context
 static const char*
 selftest (void)
 {
-  SALSA20_context_t ctx;
+  byte ctxbuf[sizeof(SALSA20_context_t) + 15];
+  SALSA20_context_t *ctx;
   byte scratch[8+1];
   byte buf[256+64+4];
   int i;
@@ -502,32 +503,35 @@ selftest (void)
   static const byte ciphertext_1[] =
     { 0xE3, 0xBE, 0x8F, 0xDD, 0x8B, 0xEC, 0xA2, 0xE3};
 
-  salsa20_setkey (&ctx, key_1, sizeof key_1);
-  salsa20_setiv  (&ctx, nonce_1, sizeof nonce_1);
+  /* 16-byte alignment required for amd64 implementation. */
+  ctx = (SALSA20_context_t *)((uintptr_t)(ctxbuf + 15) & ~(uintptr_t)15);
+
+  salsa20_setkey (ctx, key_1, sizeof key_1);
+  salsa20_setiv  (ctx, nonce_1, sizeof nonce_1);
   scratch[8] = 0;
-  salsa20_encrypt_stream (&ctx, scratch, plaintext_1, sizeof plaintext_1);
+  salsa20_encrypt_stream (ctx, scratch, plaintext_1, sizeof plaintext_1);
   if (memcmp (scratch, ciphertext_1, sizeof ciphertext_1))
     return "Salsa20 encryption test 1 failed.";
   if (scratch[8])
     return "Salsa20 wrote too much.";
-  salsa20_setkey( &ctx, key_1, sizeof(key_1));
-  salsa20_setiv  (&ctx, nonce_1, sizeof nonce_1);
-  salsa20_encrypt_stream (&ctx, scratch, scratch, sizeof plaintext_1);
+  salsa20_setkey( ctx, key_1, sizeof(key_1));
+  salsa20_setiv  (ctx, nonce_1, sizeof nonce_1);
+  salsa20_encrypt_stream (ctx, scratch, scratch, sizeof plaintext_1);
   if (memcmp (scratch, plaintext_1, sizeof plaintext_1))
     return "Salsa20 decryption test 1 failed.";
 
   for (i = 0; i < sizeof buf; i++)
     buf[i] = i;
-  salsa20_setkey (&ctx, key_1, sizeof key_1);
-  salsa20_setiv (&ctx, nonce_1, sizeof nonce_1);
+  salsa20_setkey (ctx, key_1, sizeof key_1);
+  salsa20_setiv (ctx, nonce_1, sizeof nonce_1);
   /*encrypt*/
-  salsa20_encrypt_stream (&ctx, buf, buf, sizeof buf);
+  salsa20_encrypt_stream (ctx, buf, buf, sizeof buf);
   /*decrypt*/
-  salsa20_setkey (&ctx, key_1, sizeof key_1);
-  salsa20_setiv (&ctx, nonce_1, sizeof nonce_1);
-  salsa20_encrypt_stream (&ctx, buf, buf, 1);
-  salsa20_encrypt_stream (&ctx, buf+1, buf+1, (sizeof buf)-1-1);
-  salsa20_encrypt_stream (&ctx, buf+(sizeof buf)-1, buf+(sizeof buf)-1, 1);
+  salsa20_setkey (ctx, key_1, sizeof key_1);
+  salsa20_setiv (ctx, nonce_1, sizeof nonce_1);
+  salsa20_encrypt_stream (ctx, buf, buf, 1);
+  salsa20_encrypt_stream (ctx, buf+1, buf+1, (sizeof buf)-1-1);
+  salsa20_encrypt_stream (ctx, buf+(sizeof buf)-1, buf+(sizeof buf)-1, 1);
   for (i = 0; i < sizeof buf; i++)
     if (buf[i] != (byte)i)
       return "Salsa20 encryption test 2 failed.";
