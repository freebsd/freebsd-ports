--- plugins/netflowPlugin.c.orig	2009-06-22 14:00:56.000000000 -0400
+++ plugins/netflowPlugin.c	2009-06-22 14:01:10.000000000 -0400
@@ -28,7 +28,7 @@
 static void* netflowUtilsLoop(void* _deviceId);
 #endif
 
-#define DEBUG_FLOWS
+//#define DEBUG_FLOWS
 
 #define CONST_NETFLOW_STATISTICS_HTML       "statistics.html"
 
