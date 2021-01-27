--- content/shell/browser/shell_browser_main_parts.cc.orig	2021-01-18 21:28:58 UTC
+++ content/shell/browser/shell_browser_main_parts.cc
@@ -54,7 +54,7 @@
 #if defined(USE_AURA) && defined(USE_X11)
 #include "ui/events/devices/x11/touch_factory_x11.h"  // nogncheck
 #endif
-#if !defined(OS_CHROMEOS) && defined(USE_AURA) && defined(OS_LINUX)
+#if !defined(OS_CHROMEOS) && defined(USE_AURA) && (defined(OS_LINUX) || defined(OS_BSD))
 #include "ui/base/ime/init/input_method_initializer.h"
 #endif
 #if defined(OS_CHROMEOS)
@@ -136,7 +136,7 @@ void ShellBrowserMainParts::PostMainMessageLoopStart()
 }
 
 int ShellBrowserMainParts::PreEarlyInitialization() {
-#if !defined(OS_CHROMEOS) && defined(USE_AURA) && defined(OS_LINUX)
+#if (!defined(OS_CHROMEOS) && defined(USE_AURA) && defined(OS_LINUX)) || defined(OS_BSD)
   ui::InitializeInputMethodForTesting();
 #endif
 #if defined(OS_ANDROID)
