--- content/renderer/renderer_glue.cc.orig	2011-06-24 11:30:33.000000000 +0300
+++ content/renderer/renderer_glue.cc	2011-06-26 22:17:27.417781169 +0300
@@ -34,7 +34,7 @@
 #include "webkit/glue/webkit_glue.h"
 #include "webkit/glue/websocketstreamhandle_bridge.h"
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_FREEBSD)
 #include "content/common/child_process_sandbox_support_linux.h"
 #endif
 
@@ -255,7 +255,7 @@
   RenderThread::current()->EnableSpdy(enable);
 }
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_FREEBSD)
 int MatchFontWithFallback(const std::string& face, bool bold,
                           bool italic, int charset) {
   return child_process_sandbox_support::MatchFontWithFallback(
