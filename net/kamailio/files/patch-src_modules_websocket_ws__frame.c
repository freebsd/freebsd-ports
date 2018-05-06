--- src/modules/websocket/ws_frame.c.orig	2018-03-01 16:24:10 UTC
+++ src/modules/websocket/ws_frame.c
@@ -29,7 +29,7 @@
 #ifdef EMBEDDED_UTF8_DECODE
 #include "utf8_decode.h"
 #else
-#include <unistr.h>
+/* #include <unistr.h> */
 #endif
 
 #include "../../core/events.h"
