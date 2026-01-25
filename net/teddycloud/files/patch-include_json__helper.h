--- include/json_helper.h.orig	2026-01-23 20:45:38 UTC
+++ include/json_helper.h
@@ -1,6 +1,7 @@
 #pragma once
 
-#include "cJSON.h"
+#include <cjson/cJSON.h>
+
 #include "debug.h"
 
 char *jsonGetString(cJSON *jsonElement, char *name);
