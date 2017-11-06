--- ../redis2-nginx-module-0.12/src/ngx_http_redis2_util.c.orig	2016-11-20 15:00:28.997903000 -0500
+++ ../redis2-nginx-module-0.12/src/ngx_http_redis2_util.c	2016-11-20 15:00:44.173323000 -0500
@@ -77,6 +77,7 @@
             continue;
         }
 
+#if (nginx_version < 1011006)
         if (uscfp[i]->default_port
             && url->default_port
             && uscfp[i]->default_port != url->default_port)
@@ -84,6 +85,7 @@
             dd("upstream_add: default_port not match");
             continue;
         }
+#endif
 
         return uscfp[i];
     }
