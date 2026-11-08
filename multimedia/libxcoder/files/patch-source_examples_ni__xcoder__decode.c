--- source/examples/ni_xcoder_decode.c.orig	2026-10-17 00:01:03 UTC
+++ source/examples/ni_xcoder_decode.c
@@ -32,7 +32,7 @@
 
 #ifdef _WIN32
 #include "ni_getopt.h"
-#elif __linux__ || __APPLE__
+#elif __linux__ || __APPLE__ || __FreeBSD__
 #include <getopt.h>
 #endif
 
