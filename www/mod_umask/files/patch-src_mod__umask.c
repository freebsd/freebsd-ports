--- src/mod_umask.c.orig	2004-10-12 19:03:16 UTC
+++ src/mod_umask.c
@@ -26,6 +26,7 @@
  *
  */
 
+#include <sys/stat.h>
 #include "httpd.h"
 #include "http_core.h"
 #include "http_config.h"
@@ -42,7 +43,7 @@ struct umask_config_rec
     long int mask;
 };
 
-static void *umask_create_config(apr_pool_t * p, char *dir)
+static void *umask_create_config(apr_pool_t * p, server_rec *dir)
 {
     umask_config_rec *dConfig = apr_pcalloc(p, sizeof(*dConfig));
 
