--- src/pluginscheduler.c	2020-08-11 07:00:25.000000000 -0500
+++ src/pluginscheduler.c	2021-01-04 18:10:12.943469000 -0500
@@ -33,7 +33,7 @@
 #include <glib.h>
 #include <gvm/base/prefs.h>     /* for prefs_get() */
 #include <gvm/util/nvticache.h> /* for nvticache_t */
-#include <malloc.h>
+#include <stdlib.h>
 #include <string.h> /* for strcmp() */
 
 #undef G_LOG_DOMAIN
@@ -325,7 +325,7 @@
       plugins_scheduler_free (ret);
       return NULL;
     }
-  malloc_trim (0);
+//  malloc_trim (0);
   return ret;
 }
 
@@ -427,7 +427,7 @@
           element = element->next;
         }
     }
-  malloc_trim (0);
+//  malloc_trim (0);
 }
 
 struct scheduler_plugin *
