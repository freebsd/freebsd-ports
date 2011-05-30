--- ./src/meta_data.c.orig	2011-05-30 06:58:07.055492500 -0400
+++ ./src/meta_data.c	2011-05-30 06:59:10.383490225 -0400
@@ -215,6 +215,7 @@
     return;
 
   md_entry_free (md->head);
+  pthread_mutex_destroy(&md->lock);
   free (md);
 } /* }}} void meta_data_destroy */
 
