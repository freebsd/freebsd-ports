--- file_bgf.c.orig	Thu Nov 24 13:58:48 2005
+++ file_bgf.c	Thu Nov  2 00:04:15 2006
@@ -140,7 +140,7 @@
 gint read_bgf(gchar *filename, struct model_pak *data)
 {
   gint n=0, w, i, num_tokens;
-  gchar **buff, **buff2, line[LINELEN];
+  gchar **buff, **buff2, line[LINELEN], *species_string;
   struct core_pak *core, *core_bond_to;
   
   GHashTable * atom_types_and_labels = g_hash_table_new_full(g_str_hash, g_str_equal, g_free, g_free);
@@ -278,7 +278,7 @@
   }
   
   /* allocate 25 characters for each species line, that should be enough */
-  gchar * species_string = g_new(gchar, g_hash_table_size(atom_types_and_labels) * 25 );
+  species_string = g_new(gchar, g_hash_table_size(atom_types_and_labels) * 25 );
   /* get all species from the hash table */
   g_hash_table_foreach(atom_types_and_labels, species_line_from_hash_table, &species_string);
   
