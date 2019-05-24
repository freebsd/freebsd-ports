--- content/shell/browser/web_test/web_test_browser_main_parts.cc.orig	2019-04-30 22:22:48 UTC
+++ content/shell/browser/web_test/web_test_browser_main_parts.cc
@@ -42,7 +42,7 @@
 #if defined(USE_AURA) && defined(USE_X11)
 #include "ui/events/devices/x11/touch_factory_x11.h"  // nogncheck
 #endif
-#if !defined(OS_CHROMEOS) && defined(USE_AURA) && defined(OS_LINUX)
+#if !defined(OS_CHROMEOS) && defined(USE_AURA) && (defined(OS_LINUX) || defined(OS_BSD))
 #include "ui/base/ime/input_method_initializer.h"
 #endif
 
