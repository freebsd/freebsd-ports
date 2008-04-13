--- hald/freebsd/hf-storage.c.orig	2008-04-07 00:40:06.000000000 -0400
+++ hald/freebsd/hf-storage.c	2008-04-07 00:40:37.000000000 -0400
@@ -117,6 +117,7 @@ hf_storage_geom_has_partitions (const Ge
   if (g_node_n_children(node) > 0)
     return TRUE;
 
+  /*
   if (hf_storage_class_is_partitionable(geom_obj->class) &&
       g_node_next_sibling(node) != NULL)
     {
@@ -135,6 +136,7 @@ hf_storage_geom_has_partitions (const Ge
             return TRUE;
         }
     }
+    */
 
   return FALSE;
 }
