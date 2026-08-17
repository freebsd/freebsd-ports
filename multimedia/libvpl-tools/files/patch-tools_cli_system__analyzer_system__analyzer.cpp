--- tools/cli/system_analyzer/system_analyzer.cpp.orig	2026-06-25 23:06:43 UTC
+++ tools/cli/system_analyzer/system_analyzer.cpp
@@ -14,7 +14,7 @@
 #include <vector>
 #include "vpl/mfx.h"

-#ifdef __linux__
+#ifdef __unix__
     #include <fcntl.h>
     #include <stdlib.h>
     #include <unistd.h>
