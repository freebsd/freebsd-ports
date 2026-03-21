--- spa/plugins/alsa/acp-tool.c.orig	2026-03-16 11:54:17 UTC
+++ spa/plugins/alsa/acp-tool.c
@@ -10,7 +10,9 @@
 #include <time.h>
 #include <stdbool.h>
 #include <getopt.h>
+#ifdef __linux__
 #include <alloca.h>
+#endif
 
 #include <spa/debug/context.h>
 #include <spa/utils/string.h>
