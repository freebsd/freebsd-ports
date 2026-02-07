--- src/contentJson.c.orig	2026-01-23 20:44:06 UTC
+++ src/contentJson.c
@@ -1,8 +1,9 @@
+#include <cjson/cJSON.h>
+
 #include "contentJson.h"
 
 #include "settings.h"
 #include "debug.h"
-#include "cJSON.h"
 #include "net_config.h"
 #include "server_helpers.h"
 #include "toniesJson.h"
