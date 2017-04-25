--- ../ngx_postgres-1.0rc7/src/ngx_postgres_module.c.orig	2016-11-20 15:34:25.763542000 -0500
+++ ../ngx_postgres-1.0rc7/src/ngx_postgres_module.c	2016-11-20 15:34:41.023867000 -0500
@@ -1320,12 +1320,14 @@
             continue;
         }
 
+#if (nginx_version < 1011006)
         if (uscfp[i]->default_port && url->default_port
             && (uscfp[i]->default_port != url->default_port))
         {
             dd("default_port doesn't match");
             continue;
         }
+#endif
 
         dd("returning");
         return uscfp[i];
