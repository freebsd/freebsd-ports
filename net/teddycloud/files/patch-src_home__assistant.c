--- src/home_assistant.c.orig	2026-01-23 20:47:15 UTC
+++ src/home_assistant.c
@@ -1,6 +1,7 @@
 
 #include <string.h>
 #include <math.h>
+#include <cjson/cJSON.h>
 
 #include "platform.h"
 #include "debug.h"
@@ -8,8 +9,6 @@
 #include "home_assistant.h"
 #include "macros.h"
 #include "mqtt.h"
-
-#include "cJSON.h"
 
 static int32_t coerce_int32(float value, int32_t min, int32_t max)
 {
