--- spa/plugins/alsa/alsa-compress-offload-sink.c.orig	2024-10-23 07:44:10 UTC
+++ spa/plugins/alsa/alsa-compress-offload-sink.c
@@ -7,7 +7,6 @@
 #include <assert.h>
 #include <stddef.h>
 #include <limits.h>
-#include <linux/version.h>
 
 #include <spa/monitor/device.h>
 #include <spa/debug/types.h>
