--- src/toniesJson.c.orig	2026-01-23 20:52:16 UTC
+++ src/toniesJson.c
@@ -1,10 +1,11 @@
+#include <cjson/cJSON.h>
+
 #include "toniesJson.h"
 #include "fs_port.h"
 #include "os_port.h"
 #include "settings.h"
 #include "cache.h"
 #include "debug.h"
-#include "cJSON.h"
 #include "handler.h"
 #include "cloud_request.h"
 #include "server_helpers.h"
