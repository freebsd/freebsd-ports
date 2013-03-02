--- grid.c.orig
+++ grid.c
@@ -58,7 +58,7 @@
 if (grid_table)
   g_hash_table_replace(grid_table, g_strdup(name), g_strdup(value));
 #else
-return(NULL);
+return;
 #endif
 }
 
@@ -80,7 +80,7 @@
 if (grid_table)
   g_hash_table_remove(grid_table, name);
 #else
-return(NULL);
+return;
 #endif
 }
 
