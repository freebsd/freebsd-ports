--- ./chrome/browser/shell_integration_unittest.cc.orig	2010-12-16 02:11:58.000000000 +0100
+++ ./chrome/browser/shell_integration_unittest.cc	2010-12-20 20:15:08.000000000 +0100
@@ -21,13 +21,13 @@
 
 #if defined(OS_WIN)
 #include "chrome/installer/util/browser_distribution.h"
-#elif defined(OS_LINUX)
+#elif defined(OS_LINUX) || defined(OS_FREEBSD)
 #include "base/environment.h"
-#endif  // defined(OS_LINUX)
+#endif  // defined(OS_LINUX) || defined(OS_FREEBSD)
 
 #define FPL FILE_PATH_LITERAL
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_FREEBSD)
 namespace {
 
 // Provides mock environment variables values based on a stored map.
