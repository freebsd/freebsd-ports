--- content/shell/browser/shell_browser_main_parts.cc.orig	2021-12-31 00:57:33 UTC
+++ content/shell/browser/shell_browser_main_parts.cc
@@ -49,7 +49,7 @@
 #include "net/base/network_change_notifier.h"
 #endif
 
-#if defined(USE_AURA) && (defined(OS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS))
+#if defined(USE_AURA) && (defined(OS_LINUX) || defined(OS_BSD) || BUILDFLAG(IS_CHROMEOS_LACROS))
 #include "ui/base/ime/init/input_method_initializer.h"
 #endif
 
@@ -128,7 +128,7 @@ void ShellBrowserMainParts::PostCreateMainMessageLoop(
 }
 
 int ShellBrowserMainParts::PreEarlyInitialization() {
-#if defined(USE_AURA) && (defined(OS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS))
+#if defined(USE_AURA) && (defined(OS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS) || defined(OS_BSD))
   ui::InitializeInputMethodForTesting();
 #endif
 #if defined(OS_ANDROID)
