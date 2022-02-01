--- chrome/browser/headless/headless_mode_util.cc.orig	2021-12-14 11:44:58 UTC
+++ chrome/browser/headless/headless_mode_util.cc
@@ -9,7 +9,7 @@
 // Native headless is currently available only on Linux platform. More
 // platforms will be added soon, so avoid function level clutter by providing
 // stub implementations at the end of the file.
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
 
 #include <cstdlib>
 #include <vector>
@@ -59,7 +59,7 @@ void SetUpCommandLine(const base::CommandLine* command
 
 }  // namespace headless
 
-#else  // defined(OS_LINUX)
+#else  // defined(OS_LINUX) || defined(OS_BSD)
 
 namespace headless {
 
@@ -71,4 +71,4 @@ void SetUpCommandLine(const base::CommandLine* command
 
 }  // namespace headless
 
-#endif  // defined(OS_LINUX)
+#endif  // defined(OS_LINUX) || defined(OS_BSD)
