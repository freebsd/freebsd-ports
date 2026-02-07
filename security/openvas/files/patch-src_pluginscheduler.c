--- src/pluginscheduler.c	2022-07-18 04:07:38.000000000 -0500
+++ src/pluginscheduler.c	2022-07-31 19:38:07.076865000 -0500
@@ -33,7 +33,11 @@
 #include <glib.h>
 #include <gvm/base/prefs.h>     /* for prefs_get() */
 #include <gvm/util/nvticache.h> /* for nvticache_t */
+#include <stdlib.h>
+#if !defined(__FreeBSD__)
 #include <malloc.h>
+#endif
+#include <stdlib.h>
 #include <string.h> /* for strcmp() */
 
 #undef G_LOG_DOMAIN
