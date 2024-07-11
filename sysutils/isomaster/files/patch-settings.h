--- settings.h.orig	2024-07-09 06:41:15 UTC
+++ settings.h
@@ -7,7 +7,7 @@
 #ifndef USE_SYSTEM_INIPARSER
 #include "iniparser-4.1/src/iniparser.h"
 #else
-#include <iniparser.h>
+#include <iniparser/iniparser.h>
 #endif
 #define ISOMASTER_DEFAULT_WINDOW_WIDTH 500
 #define ISOMASTER_DEFAULT_WINDOW_HEIGHT 550
