--- ../ngx_postgres-0.8/src/ngx_postgres_output.c.orig	2011-09-20 13:00:59.000000000 +0400
+++ ../ngx_postgres-0.8/src/ngx_postgres_output.c	2011-09-20 13:05:09.000000000 +0400
@@ -624,7 +624,7 @@
         return rc;
     }
 
-    ngx_chain_update_chains(&u->free_bufs, &u->busy_bufs, &cl, u->output.tag);
+    ngx_chain_update_chains(r->pool, &u->free_bufs, &u->busy_bufs, &cl, u->output.tag);
 
     dd("returning rc:%d", (int) rc);
     return rc;
