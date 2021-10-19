--- content/shell/browser/shell_browser_main_parts.cc.orig	2021-09-14 01:51:57 UTC
+++ content/shell/browser/shell_browser_main_parts.cc
@@ -60,7 +60,7 @@
 #include "ui/events/devices/x11/touch_factory_x11.h"  // nogncheck
 #endif
 
-#if defined(USE_AURA) && (defined(OS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS))
+#if defined(USE_AURA) && (defined(OS_LINUX) || defined(OS_BSD) || BUILDFLAG(IS_CHROMEOS_LACROS))
 #include "ui/base/ime/init/input_method_initializer.h"
 #endif
 
@@ -148,7 +148,7 @@ void ShellBrowserMainParts::PostCreateMainMessageLoop(
 }
 
 int ShellBrowserMainParts::PreEarlyInitialization() {
-#if defined(USE_AURA) && (defined(OS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS))
+#if defined(USE_AURA) && (defined(OS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS) || defined(OS_BSD))
   ui::InitializeInputMethodForTesting();
 #endif
 #if defined(OS_ANDROID)
