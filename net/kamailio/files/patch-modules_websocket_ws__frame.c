--- modules/websocket/ws_frame.c.orig	2015-09-05 21:18:25 UTC
+++ modules/websocket/ws_frame.c
@@ -29,7 +29,7 @@
 #ifdef EMBEDDED_UTF8_DECODE
 #include "utf8_decode.h"
 #else
-#include <unistr.h>
+/* #include <unistr.h> */
 #endif
 
 #include "../../events.h"
