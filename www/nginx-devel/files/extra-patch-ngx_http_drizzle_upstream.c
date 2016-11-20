--- ../drizzle-nginx-module-0.1.9/src/ngx_http_drizzle_upstream.c.orig	2016-11-20 15:32:37.264746000 -0500
+++ ../drizzle-nginx-module-0.1.9/src/ngx_http_drizzle_upstream.c	2016-11-20 15:33:20.909836000 -0500
@@ -1027,12 +1027,14 @@
             continue;
         }
 
+#if (nginx_version < 1011006)
         if (uscfp[i]->default_port && url->default_port
             && uscfp[i]->default_port != url->default_port)
         {
             dd("upstream_add: default_port not match");
             continue;
         }
+#endif
 
         return uscfp[i];
     }
