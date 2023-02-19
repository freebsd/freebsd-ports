--- src/spss/readstat_por.h.orig	2023-02-19 12:38:04 UTC
+++ src/spss/readstat_por.h
@@ -31,7 +31,7 @@ typedef struct por_ctx_s {
     ck_hash_table_t *var_dict;
 } por_ctx_t;
 
-por_ctx_t *por_ctx_init();
+por_ctx_t *por_ctx_init(void);
 void por_ctx_free(por_ctx_t *ctx);
 ssize_t por_utf8_encode(const unsigned char *input, size_t input_len, 
         char *output, size_t output_len, uint16_t lookup[256]);
