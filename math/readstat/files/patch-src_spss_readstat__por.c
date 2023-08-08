--- src/spss/readstat_por.c.orig	2023-04-20 20:55:14 UTC
+++ src/spss/readstat_por.c
@@ -64,7 +64,7 @@ uint16_t por_unicode_lookup[256] = {
     0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
     0, 0, 0, 0, 0, 0 };
 
-por_ctx_t *por_ctx_init() {
+por_ctx_t *por_ctx_init(void) {
     por_ctx_t *ctx = calloc(1, sizeof(por_ctx_t));
 
     ctx->space = ' ';
