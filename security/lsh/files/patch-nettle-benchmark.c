--- src/nettle/examples/nettle-benchmark.c.orig	Fri Feb 15 11:09:13 2002
+++ src/nettle/examples/nettle-benchmark.c	Wed Dec 18 05:34:29 2002
@@ -169,8 +169,15 @@
   init_data(data);
 
   {
+#ifndef __FreeBSD__
     struct bench_cipher_info info
       = { ctx, cipher->encrypt, data };
+#else
+    struct bench_cipher_info info;
+    info.ctx = ctx;
+    info.crypt = cipher->encrypt;
+    info.data = data;
+#endif
     
     init_key(cipher->key_size, key);
     cipher->set_encrypt_key(ctx, cipher->key_size, key);
@@ -180,8 +187,15 @@
   }
   
   {
+#ifndef __FreeBSD__
     struct bench_cipher_info info
       = { ctx, cipher->decrypt, data };
+#else
+    struct bench_cipher_info info;
+    info.ctx = ctx;
+    info.crypt = cipher->decrypt;
+    info.data = data;
+#endif
     
     init_key(cipher->key_size, key);
     cipher->set_decrypt_key(ctx, cipher->key_size, key);
@@ -196,8 +210,17 @@
       
       /* Do CBC mode */
       {
+#ifndef __FreeBSD__
         struct bench_cbc_info info
           = { ctx, cipher->encrypt, data, cipher->block_size, iv };
+#else
+        struct bench_cbc_info info;
+	info.ctx = ctx;
+	info.crypt = cipher->encrypt;
+	info.data = data;
+	info.block_size = cipher->block_size;
+	info.iv = iv;
+#endif
     
         memset(iv, 0, sizeof(iv));
     
@@ -208,8 +231,17 @@
       }
 
       {
+#ifndef __FreeBSD__
         struct bench_cbc_info info
           = { ctx, cipher->decrypt, data, cipher->block_size, iv };
+#else
+        struct bench_cbc_info info;
+	info.ctx = ctx;
+	info.crypt = cipher->decrypt;
+	info.data = data;
+	info.block_size = cipher->block_size;
+	info.iv = iv;
+#endif
     
         memset(iv, 0, sizeof(iv));
 
