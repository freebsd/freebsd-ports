--- ../memc-nginx-module-0.17/src/ngx_http_memc_util.c.orig	2016-11-20 14:54:02.640140000 -0500
+++ ../memc-nginx-module-0.17/src/ngx_http_memc_util.c	2016-11-20 14:54:34.579764000 -0500
@@ -141,12 +141,14 @@
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
