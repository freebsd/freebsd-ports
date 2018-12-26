--- lfd_encrypt.c.orig	2013-07-07 19:54:35 UTC
+++ lfd_encrypt.c
@@ -95,11 +95,11 @@ static unsigned long sequence_num;
 static char * pkey;
 static char * iv_buf;
 
-static EVP_CIPHER_CTX ctx_enc;	/* encrypt */
-static EVP_CIPHER_CTX ctx_dec;	/* decrypt */
+static EVP_CIPHER_CTX *ctx_enc;	/* encrypt */
+static EVP_CIPHER_CTX *ctx_dec;	/* decrypt */
 
-static EVP_CIPHER_CTX ctx_enc_ecb;	/* sideband ecb encrypt */
-static EVP_CIPHER_CTX ctx_dec_ecb;	/* sideband ecb decrypt */
+static EVP_CIPHER_CTX *ctx_enc_ecb;	/* sideband ecb encrypt */
+static EVP_CIPHER_CTX *ctx_dec_ecb;	/* sideband ecb decrypt */
 
 static int send_msg(int len, char *in, char **out);
 static int recv_msg(int len, char *in, char **out);
@@ -156,6 +156,11 @@ static int alloc_encrypt(struct vtun_host *host)
    EVP_CIPHER_CTX *pctx_enc;
    EVP_CIPHER_CTX *pctx_dec;
 
+   ctx_enc = EVP_CIPHER_CTX_new();
+   ctx_dec = EVP_CIPHER_CTX_new();
+   ctx_enc_ecb = EVP_CIPHER_CTX_new();
+   ctx_dec_ecb = EVP_CIPHER_CTX_new();
+
    enc_init_first_time = 1;   
    dec_init_first_time = 1;   
 
@@ -182,15 +187,15 @@ static int alloc_encrypt(struct vtun_host *host)
          keysize = 32;
          sb_init = 1;
          cipher_type = EVP_aes_256_ecb();
-         pctx_enc = &ctx_enc_ecb;
-         pctx_dec = &ctx_dec_ecb;
+         pctx_enc = ctx_enc_ecb;
+         pctx_dec = ctx_dec_ecb;
       break;
       
       case VTUN_ENC_AES256ECB:
          blocksize = 16;
          keysize = 32;
-         pctx_enc = &ctx_enc;
-         pctx_dec = &ctx_dec;
+         pctx_enc = ctx_enc;
+         pctx_dec = ctx_dec;
          cipher_type = EVP_aes_256_ecb();
          strcpy(cipher_name,"AES-256-ECB");
       break;      
@@ -201,14 +206,14 @@ static int alloc_encrypt(struct vtun_host *host)
          keysize = 16;
          sb_init=1;
          cipher_type = EVP_aes_128_ecb();
-         pctx_enc = &ctx_enc_ecb;
-         pctx_dec = &ctx_dec_ecb;
+         pctx_enc = ctx_enc_ecb;
+         pctx_dec = ctx_dec_ecb;
       break;
       case VTUN_ENC_AES128ECB:
          blocksize = 16;
          keysize = 16;
-         pctx_enc = &ctx_enc;
-         pctx_dec = &ctx_dec;
+         pctx_enc = ctx_enc;
+         pctx_dec = ctx_dec;
          cipher_type = EVP_aes_128_ecb();
          strcpy(cipher_name,"AES-128-ECB");
       break;
@@ -221,16 +226,16 @@ static int alloc_encrypt(struct vtun_host *host)
          var_key = 1;
          sb_init = 1;
          cipher_type = EVP_bf_ecb();
-         pctx_enc = &ctx_enc_ecb;
-         pctx_dec = &ctx_dec_ecb;
+         pctx_enc = ctx_enc_ecb;
+         pctx_dec = ctx_dec_ecb;
       break;
 
       case VTUN_ENC_BF256ECB:
          blocksize = 8;
          keysize = 32;
          var_key = 1;
-         pctx_enc = &ctx_enc;
-         pctx_dec = &ctx_dec;
+         pctx_enc = ctx_enc;
+         pctx_dec = ctx_dec;
          cipher_type = EVP_bf_ecb();
          strcpy(cipher_name,"Blowfish-256-ECB");
       break;
@@ -243,16 +248,16 @@ static int alloc_encrypt(struct vtun_host *host)
          var_key = 1;
          sb_init = 1;
          cipher_type = EVP_bf_ecb();
-         pctx_enc = &ctx_enc_ecb;
-         pctx_dec = &ctx_dec_ecb;
+         pctx_enc = ctx_enc_ecb;
+         pctx_dec = ctx_dec_ecb;
       break;
       case VTUN_ENC_BF128ECB: /* blowfish 128 ecb is the default */
       default:
          blocksize = 8;
          keysize = 16;
          var_key = 1;
-         pctx_enc = &ctx_enc;
-         pctx_dec = &ctx_dec;
+         pctx_enc = ctx_enc;
+         pctx_dec = ctx_dec;
          cipher_type = EVP_bf_ecb();
          strcpy(cipher_name,"Blowfish-128-ECB");
       break;
@@ -294,10 +299,10 @@ static int free_encrypt()
    lfd_free(enc_buf); enc_buf = NULL;
    lfd_free(dec_buf); dec_buf = NULL;
 
-   EVP_CIPHER_CTX_cleanup(&ctx_enc);
-   EVP_CIPHER_CTX_cleanup(&ctx_dec);
-   EVP_CIPHER_CTX_cleanup(&ctx_enc_ecb);
-   EVP_CIPHER_CTX_cleanup(&ctx_dec_ecb);
+   EVP_CIPHER_CTX_cleanup(ctx_enc);
+   EVP_CIPHER_CTX_cleanup(ctx_dec);
+   EVP_CIPHER_CTX_cleanup(ctx_enc_ecb);
+   EVP_CIPHER_CTX_cleanup(ctx_dec_ecb);
 
    return 0;
 }
@@ -323,7 +328,7 @@ static int encrypt_buf(int len, char *in, char **out)
    outlen=len+pad;
    if (pad == blocksize)
       RAND_bytes(in_ptr+len, blocksize-1);
-   EVP_EncryptUpdate(&ctx_enc, out_ptr, &outlen, in_ptr, len+pad);
+   EVP_EncryptUpdate(ctx_enc, out_ptr, &outlen, in_ptr, len+pad);
    *out = enc_buf;
 
    sequence_num++;
@@ -343,7 +348,7 @@ static int decrypt_buf(int len, char *in, char **out)
 
    outlen=len;
    if (!len) return 0;
-   EVP_DecryptUpdate(&ctx_dec, out_ptr, &outlen, in_ptr, len);
+   EVP_DecryptUpdate(ctx_dec, out_ptr, &outlen, in_ptr, len);
    recv_ib_mesg(&outlen, &out_ptr);
    if (!outlen) return 0;
    tmp_ptr = out_ptr + outlen; tmp_ptr--;
@@ -431,13 +436,13 @@ static int cipher_enc_init(char * iv)
       break;
    } /* switch(cipher) */
 
-   EVP_CIPHER_CTX_init(&ctx_enc);
-   EVP_EncryptInit_ex(&ctx_enc, cipher_type, NULL, NULL, NULL);
+   EVP_CIPHER_CTX_init(ctx_enc);
+   EVP_EncryptInit_ex(ctx_enc, cipher_type, NULL, NULL, NULL);
    if (var_key)
-      EVP_CIPHER_CTX_set_key_length(&ctx_enc, keysize);
-   EVP_EncryptInit_ex(&ctx_enc, NULL, NULL, pkey, NULL);
-   EVP_EncryptInit_ex(&ctx_enc, NULL, NULL, NULL, iv);
-   EVP_CIPHER_CTX_set_padding(&ctx_enc, 0);
+      EVP_CIPHER_CTX_set_key_length(ctx_enc, keysize);
+   EVP_EncryptInit_ex(ctx_enc, NULL, NULL, pkey, NULL);
+   EVP_EncryptInit_ex(ctx_enc, NULL, NULL, NULL, iv);
+   EVP_CIPHER_CTX_set_padding(ctx_enc, 0);
    if (enc_init_first_time)
    {
       sprintf(tmpstr,"%s encryption initialized", cipher_name);
@@ -521,13 +526,13 @@ static int cipher_dec_init(char * iv)
       break;
    } /* switch(cipher) */
 
-   EVP_CIPHER_CTX_init(&ctx_dec);
-   EVP_DecryptInit_ex(&ctx_dec, cipher_type, NULL, NULL, NULL);
+   EVP_CIPHER_CTX_init(ctx_dec);
+   EVP_DecryptInit_ex(ctx_dec, cipher_type, NULL, NULL, NULL);
    if (var_key)
-      EVP_CIPHER_CTX_set_key_length(&ctx_dec, keysize);
-   EVP_DecryptInit_ex(&ctx_dec, NULL, NULL, pkey, NULL);
-   EVP_DecryptInit_ex(&ctx_dec, NULL, NULL, NULL, iv);
-   EVP_CIPHER_CTX_set_padding(&ctx_dec, 0);
+      EVP_CIPHER_CTX_set_key_length(ctx_dec, keysize);
+   EVP_DecryptInit_ex(ctx_dec, NULL, NULL, pkey, NULL);
+   EVP_DecryptInit_ex(ctx_dec, NULL, NULL, NULL, iv);
+   EVP_CIPHER_CTX_set_padding(ctx_dec, 0);
    if (dec_init_first_time)
    {
       sprintf(tmpstr,"%s decryption initialized", cipher_name);
@@ -559,7 +564,7 @@ static int send_msg(int len, char *in, char **out)
 
          in_ptr = in - blocksize*2;
          outlen = blocksize*2;
-         EVP_EncryptUpdate(&ctx_enc_ecb, in_ptr, 
+         EVP_EncryptUpdate(ctx_enc_ecb, in_ptr, 
             &outlen, in_ptr, blocksize*2);
          *out = in_ptr;
          len = outlen;
@@ -586,7 +591,7 @@ static int recv_msg(int len, char *in, char **out)
          in_ptr = in;
          iv = malloc(blocksize);
          outlen = blocksize*2;
-         EVP_DecryptUpdate(&ctx_dec_ecb, in_ptr, &outlen, in_ptr, blocksize*2);
+         EVP_DecryptUpdate(ctx_dec_ecb, in_ptr, &outlen, in_ptr, blocksize*2);
          
          if ( !strncmp(in_ptr, "ivec", 4) )
          {
@@ -629,7 +634,7 @@ static int recv_msg(int len, char *in, char **out)
                if (cipher_enc_state != CIPHER_INIT)
                {
                   cipher_enc_state = CIPHER_INIT;
-                  EVP_CIPHER_CTX_cleanup(&ctx_enc);
+                  EVP_CIPHER_CTX_cleanup(ctx_enc);
 #ifdef LFD_ENCRYPT_DEBUG
                   vtun_syslog(LOG_INFO, 
                      "Forcing local encryptor re-init");
@@ -710,7 +715,7 @@ static int recv_ib_mesg(int *len, char **in)
          if (cipher_enc_state != CIPHER_INIT)
          {
             cipher_enc_state = CIPHER_INIT;
-            EVP_CIPHER_CTX_cleanup(&ctx_enc);
+            EVP_CIPHER_CTX_cleanup(ctx_enc);
          }
 #ifdef LFD_ENCRYPT_DEBUG
          vtun_syslog(LOG_INFO, "Remote requests encryptor re-init");
@@ -724,7 +729,7 @@ static int recv_ib_mesg(int *len, char **in)
              cipher_enc_state != CIPHER_REQ_INIT &&
              cipher_enc_state != CIPHER_INIT)
          {
-            EVP_CIPHER_CTX_cleanup (&ctx_dec);
+            EVP_CIPHER_CTX_cleanup (ctx_dec);
             cipher_dec_state = CIPHER_INIT;
             cipher_enc_state = CIPHER_REQ_INIT;
          }
