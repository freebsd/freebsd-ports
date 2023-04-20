--- src/spss/readstat_por_write.c.orig	2023-04-20 20:55:14 UTC
+++ src/spss/readstat_por_write.c
@@ -167,7 +167,7 @@ static readstat_error_t por_write_string_field(readsta
     return por_write_string_field_n(writer, ctx, string, strlen(string));
 }
 
-static por_write_ctx_t *por_write_ctx_init() {
+static por_write_ctx_t *por_write_ctx_init(void) {
     por_write_ctx_t *ctx = calloc(1, sizeof(por_write_ctx_t));
     uint16_t max_unicode = 0;
     int i;
