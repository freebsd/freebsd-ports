--- content/shell/browser/shell_browser_main_parts.cc.orig	2022-04-21 18:48:31 UTC
+++ content/shell/browser/shell_browser_main_parts.cc
@@ -50,7 +50,7 @@
 #include "net/base/network_change_notifier.h"
 #endif
 
-#if defined(USE_AURA) && (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS))
+#if defined(USE_AURA) && (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS) || BUILDFLAG(IS_BSD))
 #include "ui/base/ime/init/input_method_initializer.h"
 #endif
 
@@ -130,7 +130,7 @@ void ShellBrowserMainParts::PostCreateMainMessageLoop(
 }
 
 int ShellBrowserMainParts::PreEarlyInitialization() {
-#if defined(USE_AURA) && (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS))
+#if defined(USE_AURA) && (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS) || BUILDFLAG(IS_BSD))
   ui::InitializeInputMethodForTesting();
 #endif
 #if BUILDFLAG(IS_ANDROID)
