--- csv.h.orig	2012-12-28 22:50:44 UTC
+++ csv.h
@@ -79,6 +79,7 @@ void csv_set_term_func(struct csv_parser
 void csv_set_realloc_func(struct csv_parser *p, void *(*)(void *, size_t));
 void csv_set_free_func(struct csv_parser *p, void (*)(void *));
 void csv_set_blk_size(struct csv_parser *p, size_t);
+size_t csv_get_blk_size(struct csv_parser *p);
 size_t csv_get_buffer_size(struct csv_parser *p);
 
 #ifdef __cplusplus
