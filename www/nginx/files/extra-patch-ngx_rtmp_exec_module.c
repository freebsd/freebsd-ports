--- ../arut-nginx-rtmp-module-80db4c4/ngx_rtmp_exec_module.c.orig	2012-06-14 15:14:50.000000000 +0400
+++ ../arut-nginx-rtmp-module-80db4c4/ngx_rtmp_exec_module.c	2012-06-14 15:15:06.000000000 +0400
@@ -4,7 +4,11 @@
 
 
 #include "ngx_rtmp_cmd_module.h"
+#ifdef NGX_FREEBSD
+#include <stdlib.h>
+#else
 #include <malloc.h>
+#endif
 
 #ifdef NGX_LINUX
 #include <unistd.h>
