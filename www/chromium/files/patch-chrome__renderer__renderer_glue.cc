--- ./chrome/renderer/renderer_glue.cc.orig	2010-12-16 02:11:59.000000000 +0100
+++ ./chrome/renderer/renderer_glue.cc	2010-12-20 20:15:08.000000000 +0100
@@ -38,7 +38,7 @@
 
 #if defined(OS_WIN)
 #include <strsafe.h>  // note: per msdn docs, this must *follow* other includes
-#elif defined(OS_LINUX)
+#elif defined(OS_LINUX) || defined(OS_FREEBSD)
 #include "chrome/renderer/renderer_sandbox_support_linux.h"
 #endif
 
@@ -274,7 +274,7 @@
       new ViewHostMsg_UserMetricsRecordAction(action));
 }
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_FREEBSD)
 int MatchFontWithFallback(const std::string& face, bool bold,
                           bool italic, int charset) {
   return renderer_sandbox_support::MatchFontWithFallback(
