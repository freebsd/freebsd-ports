--- crypto/include/sha1.h.orig	2014-10-13 14:35:33 UTC
+++ crypto/include/sha1.h
@@ -68,17 +68,20 @@ typedef EVP_MD_CTX sha1_ctx_t;
  *
  */
 
+static
 void inline sha1_init (sha1_ctx_t *ctx)
 {
     EVP_MD_CTX_init(ctx);
     EVP_DigestInit(ctx, EVP_sha1());
 }
 
+static
 void inline sha1_update (sha1_ctx_t *ctx, const uint8_t *M, int octets_in_msg)
 {
     EVP_DigestUpdate(ctx, M, octets_in_msg);
 }
 
+static
 void inline sha1_final (sha1_ctx_t *ctx, uint32_t *output)
 {
     unsigned int len = 0;
