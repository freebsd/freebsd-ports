--- content/renderer/renderer_glue.cc.orig	2011-05-06 12:02:55.000000000 +0300
+++ content/renderer/renderer_glue.cc	2011-06-04 16:01:20.943412500 +0300
@@ -34,7 +34,7 @@
 #include "webkit/glue/webkit_glue.h"
 #include "webkit/glue/websocketstreamhandle_bridge.h"
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_FREEBSD)
 #include "content/renderer/renderer_sandbox_support_linux.h"
 #endif
 
@@ -259,7 +259,7 @@
   RenderThread::current()->EnableSpdy(enable);
 }
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_FREEBSD)
 int MatchFontWithFallback(const std::string& face, bool bold,
                           bool italic, int charset) {
   return renderer_sandbox_support::MatchFontWithFallback(
