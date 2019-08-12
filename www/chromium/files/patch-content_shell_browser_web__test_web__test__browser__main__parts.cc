--- content/shell/browser/web_test/web_test_browser_main_parts.cc.orig	2019-07-24 18:58:25 UTC
+++ content/shell/browser/web_test/web_test_browser_main_parts.cc
@@ -37,7 +37,7 @@
 #if defined(USE_AURA) && defined(USE_X11)
 #include "ui/events/devices/x11/touch_factory_x11.h"  // nogncheck
 #endif
-#if !defined(OS_CHROMEOS) && defined(USE_AURA) && defined(OS_LINUX)
+#if !defined(OS_CHROMEOS) && defined(USE_AURA) && (defined(OS_LINUX) || defined(OS_BSD))
 #include "ui/base/ime/init/input_method_initializer.h"
 #endif
 
