--- lib/ftxlate.c.orig	2019-03-21 19:39:03 UTC
+++ lib/ftxlate.c
@@ -2040,21 +2040,21 @@ static int cryptopan_init(struct cryptopan *cp, unsign
 
 
   /* init crypto */
-  if (!(cp->cipher_ctx = (EVP_CIPHER_CTX*) malloc(sizeof(EVP_CIPHER_CTX)))) {
+  cp->cipher_ctx = EVP_CIPHER_CTX_new();
+  if (cp->cipher_ctx == NULL)
     return -1;
-  }
 
-  EVP_CIPHER_CTX_init(cp->cipher_ctx);
-
   /* disable padding */
   if (!(EVP_CIPHER_CTX_set_padding(cp->cipher_ctx, 0))) {
     cryptopan_free(cp);
+    EVP_CIPHER_CTX_free(cp->cipher_ctx);
     return -1;
   }
 
   /* init encryption */
   if (!(EVP_EncryptInit(cp->cipher_ctx, EVP_aes_128_ecb(), key, NULL))) {
     cryptopan_free(cp);
+    EVP_CIPHER_CTX_free(cp->cipher_ctx);
     return -1;
   }
 
@@ -2062,8 +2062,10 @@ static int cryptopan_init(struct cryptopan *cp, unsign
   i = 16;
   if (!(EVP_EncryptUpdate(cp->cipher_ctx, cp->m_pad, &i, key+16, i))) {
     cryptopan_free(cp);
+    EVP_CIPHER_CTX_free(cp->cipher_ctx);
     return -1;
   }
+  EVP_CIPHER_CTX_free(cp->cipher_ctx);
 
 #endif /* HAVE_OPENSSL */
 
