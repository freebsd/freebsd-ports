--- ../nginx_uploadprogress_module-0.7/ngx_http_uploadprogress_module.c.orig	2009-11-21 21:48:48.000000000 +0300
+++ ../nginx_uploadprogress_module-0.7/ngx_http_uploadprogress_module.c	2009-12-19 13:09:52.000000000 +0300
@@ -1475,6 +1475,9 @@
 
     ngx_memzero(&sc, sizeof(ngx_http_script_compile_t));
 
+    t->lengths = NULL;
+    t->values = NULL;
+
     sc.cf = cf;
     sc.source = source;
     sc.lengths = &t->lengths;
