--- src/serialize.c.orig	2023-10-27 04:54:49 UTC
+++ src/serialize.c
@@ -1788,11 +1788,11 @@ static void
 pm_serialize_magic_comment(pm_parser_t *parser, pm_magic_comment_t *magic_comment, pm_buffer_t *buffer) {
     // serialize key location
     pm_buffer_append_u32(buffer, pm_ptrdifft_to_u32(magic_comment->key_start - parser->start));
-    pm_buffer_append_u32(buffer, pm_ptrdifft_to_u32(magic_comment->key_length));
+    pm_buffer_append_u32(buffer, pm_ptrdifft_to_u32((ptrdiff_t) magic_comment->key_length));
 
     // serialize value location
     pm_buffer_append_u32(buffer, pm_ptrdifft_to_u32(magic_comment->value_start - parser->start));
-    pm_buffer_append_u32(buffer, pm_ptrdifft_to_u32(magic_comment->value_length));
+    pm_buffer_append_u32(buffer, pm_ptrdifft_to_u32((ptrdiff_t) magic_comment->value_length));
 }
 
 static void
