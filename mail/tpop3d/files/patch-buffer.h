--- buffer.h.orig	2008-03-31 19:37:15 UTC
+++ buffer.h
@@ -41,7 +41,7 @@ void buffer_make_contiguous(buffer B);
 char *buffer_get_consume_ptr(buffer B, size_t *slen);
 void buffer_consume_bytes(buffer B, const size_t num);
 char *buffer_consume_all(buffer B, char *str, size_t *slen);
-char *buffer_consume_to_mark(buffer B, const char *mark, const size_t mlen, char *str, size_t *slen);
+char *buffer_consume_to_mark(buffer B, const char *mark, char *str, size_t *slen);
 void buffer_expand(buffer B, const size_t num);
 void buffer_push_data(buffer B, const char *data, const size_t dlen);
 char *buffer_get_push_ptr(buffer B, size_t *len);
