--- content/shell/browser/shell_browser_main_parts.cc.orig	2019-03-11 22:00:58 UTC
+++ content/shell/browser/shell_browser_main_parts.cc
@@ -48,7 +48,7 @@
 #if defined(USE_AURA) && defined(USE_X11)
 #include "ui/events/devices/x11/touch_factory_x11.h"  // nogncheck
 #endif
-#if !defined(OS_CHROMEOS) && defined(USE_AURA) && defined(OS_LINUX)
+#if !defined(OS_CHROMEOS) && defined(USE_AURA) && (defined(OS_BSD) || defined(OS_LINUX))
 #include "ui/base/ime/input_method_initializer.h"
 #endif
 #if defined(OS_CHROMEOS)
@@ -126,7 +126,7 @@ int ShellBrowserMainParts::PreEarlyInitialization() {
 #if defined(USE_X11)
   ui::SetDefaultX11ErrorHandlers();
 #endif
-#if !defined(OS_CHROMEOS) && defined(USE_AURA) && defined(OS_LINUX)
+#if !defined(OS_CHROMEOS) && defined(USE_AURA) && (defined(OS_BSD) || defined(OS_LINUX))
   ui::InitializeInputMethodForTesting();
 #endif
 #if defined(OS_ANDROID)
