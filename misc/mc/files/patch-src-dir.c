--- src/dir.c.orig	Tue Jan 21 06:41:45 2003
+++ src/dir.c	Tue Jun 15 03:15:09 2004
@@ -503,9 +503,11 @@
     }
 
     if (next_free) {
+	char *path = vfs_canon (".");
 	/* Add ".." except the root directory */
-	if (strcmp (vfs_canon ("."), "/") != 0)
+	if (strcmp (path, "/") != 0)
 	    add_dotdot_to_list (list, next_free++);
+	g_free (path);
 	do_sort (list, sort, next_free - 1, reverse, case_sensitive);
     } else {
 	tree_store_end_check ();
@@ -576,7 +578,7 @@
     int i, status, link_to_dir, stale_link;
     struct stat buf;
     int marked_cnt;
-    GHashTable *marked_files = g_hash_table_new (g_str_hash, g_str_equal);
+    GHashTable *marked_files;
 
     tree_store_start_check_cwd ();
     dirp = mc_opendir (".");
@@ -587,6 +589,7 @@
 	return set_zero_dir (list);
     }
 
+    marked_files = g_hash_table_new (g_str_hash, g_str_equal);
     alloc_dir_copy (list->size);
     for (marked_cnt = i = 0; i < count; i++) {
 	dir_copy.list[i].fnamelen = list->list[i].fnamelen;
@@ -622,6 +625,7 @@
 	       clean_dir (&dir_copy, count);
 	     */
 	    tree_store_end_check ();
+	    g_hash_table_destroy (marked_files);
 	    return next_free;
 	}
 
@@ -655,9 +659,11 @@
     tree_store_end_check ();
     g_hash_table_destroy (marked_files);
     if (next_free) {
+	char *path = vfs_canon (".");
 	/* Add ".." except the root directory */
-	if (strcmp (vfs_canon ("."), "/") != 0)
+	if (strcmp (path, "/") != 0)
 	    add_dotdot_to_list (list, next_free++);
+	g_free (path);
 	do_sort (list, sort, next_free - 1, rev, case_sensitive);
     } else
 	next_free = set_zero_dir (list);
