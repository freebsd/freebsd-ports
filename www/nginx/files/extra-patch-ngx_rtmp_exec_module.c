--- ../arut-nginx-rtmp-module-f7f24ba/ngx_rtmp_exec_module.c.orig	2012-07-31 20:59:43.000000000 +0400
+++ ../arut-nginx-rtmp-module-f7f24ba/ngx_rtmp_exec_module.c	2012-07-31 21:00:28.000000000 +0400
@@ -4,7 +4,11 @@
 
 
 #include "ngx_rtmp_cmd_module.h"
+#ifdef NGX_FREEBSD
+#include <stdlib.h>
+#else
 #include <malloc.h>
+#endif
 
 #ifdef NGX_LINUX
 #include <unistd.h>
