--- src/handler_api.c.orig	2026-01-23 20:46:20 UTC
+++ src/handler_api.c
@@ -5,6 +5,7 @@
 #include <stdint.h>
 #include <string.h>
 #include <stdio.h>
+#include <cjson/cJSON.h>
 
 #include "path.h"
 #include "path_ext.h"
@@ -16,7 +17,6 @@
 #include "settings.h"
 #include "stats.h"
 #include "returncodes.h"
-#include "cJSON.h"
 #include "toniefile.h"
 #include "toniesJson.h"
 #include "fs_ext.h"
