--- ftd_core/src/ftd_http_curl.c.orig	Tue May  1 22:53:17 2007
+++ ftd_core/src/ftd_http_curl.c	Tue May  1 22:53:31 2007
@@ -70,6 +70,7 @@
 #include <easy.h> /* new for v7 */
 #include <time.h>
 
+#define OS	"FreeBSD"
 #include "ftd4linux.h"
 #include "ftd_app_core.h"
 #include "ftd_config.h"
