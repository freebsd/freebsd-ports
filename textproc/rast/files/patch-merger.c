--- src/merger.c.orig	Wed Jan  4 21:41:15 2006
+++ src/merger.c	Wed Jan  4 21:41:34 2006
@@ -48,6 +48,7 @@
         }
     }
 
+    {
     rast_merger_t *db = (rast_merger_t *)
         apr_palloc(pool, sizeof(rast_merger_t));
     *base = (rast_db_t *) db;
@@ -58,6 +59,7 @@
     db->merged_dbs = merge_dbs;
     db->properties = NULL;
     db->num_properties = 0;
+    }
     return RAST_OK;
 }
 
