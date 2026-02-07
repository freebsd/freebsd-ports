--- nasl/nasl_init.c	2020-12-31 17:24:31.913454000 -0500
+++ nasl/nasl_init.c	2020-12-31 17:25:42.418759000 -0500
@@ -38,6 +38,8 @@
 
 #include <stdlib.h> /* for getenv.  */
 #include <string.h> /* for memset */
+#include <sys/types.h>
+#include <sys/socket.h>
 /* to e.g. favour BSD, but also for IPPROTO_TCP and TH_FIN */
 #include "nasl_raw.h"
 #include "nasl_scanner_glue.h"
