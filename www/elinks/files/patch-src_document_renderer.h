--- src/document/renderer.h.orig	2025-12-25 11:06:07 UTC
+++ src/document/renderer.h
@@ -16,7 +16,7 @@ void render_document_frames(struct session *ses, int n
 
 void render_document(struct view_state *, struct document_view *, struct document_options *);
 void render_document_frames(struct session *ses, int no_cache);
-struct conv_table *get_convert_table(char *head, int to_cp, int default_cp, int *from_cp, enum cp_status *cp_status, int ignore_server_cp);
+struct conv_table *get_convert_table(const char *head, int to_cp, int default_cp, int *from_cp, enum cp_status *cp_status, int ignore_server_cp);
 void compress_empty_lines(struct document *document);
 void sort_links(struct document *document);
 
