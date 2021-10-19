--- ui/gl/test/gl_surface_test_support.cc.orig	2021-09-24 18:58:09 UTC
+++ ui/gl/test/gl_surface_test_support.cc
@@ -14,7 +14,7 @@
 #include "ui/gl/gl_switches.h"
 #include "ui/gl/init/gl_factory.h"
 
-#if defined(OS_LINUX) || defined(OS_CHROMEOS)
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
 #include "ui/platform_window/common/platform_window_defaults.h"  // nogncheck
 #endif
 
@@ -43,7 +43,7 @@ void InitializeOneOffHelper(bool init_extensions) {
   }
 #endif
 
-#if defined(OS_LINUX) || defined(OS_CHROMEOS)
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
   ui::test::EnableTestConfigForPlatformWindows();
 #endif
 
