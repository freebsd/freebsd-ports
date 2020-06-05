--- ../nginx-link-function-3.2.3/src/ngx_link_func_module.c.orig	2020-01-24 10:32:50.550797000 -0500
+++ ../nginx-link-function-3.2.3/src/ngx_link_func_module.c	2020-01-24 10:33:17.135348000 -0500
@@ -35,7 +35,7 @@
 #include <ngx_config.h>
 #include <ngx_core.h>
 #include <ngx_http.h>
-#include <ngx_link_func_module.h>
+#include "ngx_link_func_module.h"
 
 #define MODULE_NAME "nginx_link_function"
 
