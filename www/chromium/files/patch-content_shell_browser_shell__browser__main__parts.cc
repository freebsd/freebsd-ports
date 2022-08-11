--- content/shell/browser/shell_browser_main_parts.cc.orig	2022-06-17 14:20:10 UTC
+++ content/shell/browser/shell_browser_main_parts.cc
@@ -50,7 +50,7 @@
 #include "net/base/network_change_notifier.h"
 #endif
 
-#if defined(USE_AURA) && (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS))
+#if defined(USE_AURA) && (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS) || BUILDFLAG(IS_BSD))
 #include "ui/base/ime/init/input_method_initializer.h"
 #endif
 
@@ -65,7 +65,7 @@
 #include "chromeos/lacros/dbus/lacros_dbus_thread_manager.h"
 #endif
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "ui/views/linux_ui/linux_ui.h"  // nogncheck
 #include "ui/views/linux_ui/linux_ui_factory.h"  // nogncheck
 #endif
@@ -129,7 +129,7 @@ void ShellBrowserMainParts::PostCreateMainMessageLoop(
 }
 
 int ShellBrowserMainParts::PreEarlyInitialization() {
-#if defined(USE_AURA) && (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS))
+#if defined(USE_AURA) && (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS) || BUILDFLAG(IS_BSD))
   ui::InitializeInputMethodForTesting();
 #endif
 #if BUILDFLAG(IS_ANDROID)
@@ -153,7 +153,7 @@ void ShellBrowserMainParts::ToolkitInitialized() {
   if (switches::IsRunWebTestsSwitchPresent())
     return;
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   views::LinuxUI::SetInstance(CreateLinuxUi());
 #endif
 }
@@ -196,7 +196,7 @@ void ShellBrowserMainParts::PostMainMessageLoopRun() {
   ShellDevToolsManagerDelegate::StopHttpHandler();
   browser_context_.reset();
   off_the_record_browser_context_.reset();
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   views::LinuxUI::SetInstance(nullptr);
 #endif
   performance_manager_lifetime_.reset();
