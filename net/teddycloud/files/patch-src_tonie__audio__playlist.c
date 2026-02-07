--- src/tonie_audio_playlist.c.orig	2026-01-23 20:51:18 UTC
+++ src/tonie_audio_playlist.c
@@ -1,9 +1,10 @@
+#include <cjson/cJSON.h>
+
 #include "tonie_audio_playlist.h"
 
 #include "fs_port.h"
 #include "toniefile.h"
 #include "server_helpers.h"
-#include "cJSON.h"
 #include "json_helper.h"
 #include "handler.h"
 
