--- src/main.c.orig	2026-01-23 20:47:56 UTC
+++ src/main.c
@@ -7,10 +7,10 @@
 #include <stdint.h>
 #include <math.h>
 #include <getopt.h>
+#include <cjson/cJSON.h>
 
 #include "error.h"
 #include "debug.h"
-#include "cJSON.h"
 #include "esp32.h"
 
 #include "version.h"
