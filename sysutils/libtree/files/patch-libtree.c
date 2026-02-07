--- libtree.c.orig	2022-02-22 22:39:24 UTC
+++ libtree.c
@@ -1514,7 +1514,7 @@ static void parse_ld_library_path(struct libtree_state
 static void set_default_paths(struct libtree_state_t *s) {
     s->default_paths_offset = s->string_table.n;
     // TODO: how to retrieve this list properly at runtime?
-    string_table_store(&s->string_table, "/lib:/lib64:/usr/lib:/usr/lib64");
+    string_table_store(&s->string_table, "/lib:/usr/lib:/usr/lib/compat:/usr/local/lib");
 }
 
 static void libtree_state_init(struct libtree_state_t *s) {
