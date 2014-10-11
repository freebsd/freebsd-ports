Make plugin ready for met.no locationforecast-1.2 API (bug #10916).

--- panel-plugin/weather-parsers.c.orig	2013-02-01 15:18:50 UTC
+++ panel-plugin/weather-parsers.c
@@ -28,6 +28,7 @@
 #define _XOPEN_SOURCE
 #define _XOPEN_SOURCE_EXTENDED 1
 #include "weather-parsers.h"
+#include "weather-translate.h"
 #include "weather-debug.h"
 
 #include <time.h>
@@ -196,8 +197,8 @@
         }
         if (NODE_IS_TYPE(child_node, "symbol")) {
             g_free(loc->symbol);
-            loc->symbol = PROP(child_node, "id");
             loc->symbol_id = strtol(PROP(child_node, "number"), NULL, 10);
+            loc->symbol = g_strdup(get_symbol_for_id(loc->symbol_id));
         }
     }
 
