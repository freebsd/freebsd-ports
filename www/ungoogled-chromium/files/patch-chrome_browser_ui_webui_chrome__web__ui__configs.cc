--- chrome/browser/ui/webui/chrome_web_ui_configs.cc.orig	2026-10-31 12:09:36 UTC
+++ chrome/browser/ui/webui/chrome_web_ui_configs.cc
@@ -177,7 +177,7 @@
 #include "chrome/browser/ui/webui/default_browser/visual_guided_setter_ui.h"
 #endif  // BUILDFLAG(IS_WIN)
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "chrome/browser/ui/webui/app_settings/web_app_settings_ui.h"
 #include "chrome/browser/ui/webui/browser_switch/browser_switch_ui.h"
 #include "chrome/browser/ui/webui/signin/history_sync_optin/history_sync_optin_ui.h"
@@ -186,13 +186,13 @@
 #endif  // BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || \
-    BUILDFLAG(IS_ANDROID)
+    BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_BSD)
 #include "chrome/browser/ui/webui/sandbox/sandbox_internals_ui.h"
 #endif  // BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) ||
         // BUILDFLAG(IS_ANDROID)
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_DESKTOP_ANDROID)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_DESKTOP_ANDROID) || BUILDFLAG(IS_BSD)
 #include "chrome/browser/ui/webui/discards/discards_ui.h"
 #endif
 
@@ -224,7 +224,7 @@
 #include "chrome/browser/ui/webui/signin/signin_error_ui.h"
 #endif  //  !BUILDFLAG(IS_CHROMEOS) && !BUILDFLAG(IS_ANDROID)
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "chrome/browser/ui/webui/on_device_translation_internals/on_device_translation_internals_ui.h"
 #endif  // BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
 
@@ -241,7 +241,7 @@
 #endif  // BUILDFLAG(IS_MAC)
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 #include "chrome/browser/ui/webui/skills/skills_ui.h"
 #endif  // BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
         // BUILDFLAG(IS_CHROMEOS)
@@ -417,10 +417,10 @@ void RegisterChromeWebUIConfigs() {
   map.AddWebUIConfig(std::make_unique<WebUIToolbarConfig>());
 #endif  // BUILDFLAG(IS_ANDROID)
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_OPENBSD)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   map.AddWebUIConfig(std::make_unique<LinuxProxyConfigUI>());
 #endif  // BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) ||
-        // BUILDFLAG(IS_OPENBSD)
+        // BUILDFLAG(IS_BSD)
 
 #if BUILDFLAG(ENABLE_EXTENSIONS_CORE)
   map.AddWebUIConfig(std::make_unique<extensions::ExtensionsUIConfig>());
@@ -448,7 +448,7 @@ void RegisterChromeWebUIConfigs() {
   map.AddWebUIConfig(std::make_unique<VisualGuidedSetterUIConfig>());
 #endif  // BUILDFLAG(IS_WIN)
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   map.AddWebUIConfig(std::make_unique<BrowserSwitchUIConfig>());
   map.AddWebUIConfig(std::make_unique<HistorySyncOptinUIConfig>());
   map.AddWebUIConfig(std::make_unique<OnDeviceTranslationInternalsUIConfig>());
@@ -457,17 +457,17 @@ void RegisterChromeWebUIConfigs() {
 #endif  // BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || \
-    BUILDFLAG(IS_ANDROID)
+    BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_BSD)
   map.AddWebUIConfig(std::make_unique<SandboxInternalsUIConfig>());
 #endif  // BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) ||
         // BUILDFLAG(IS_ANDROID)
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_DESKTOP_ANDROID)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_DESKTOP_ANDROID) || BUILDFLAG(IS_BSD)
   map.AddWebUIConfig(std::make_unique<DiscardsUIConfig>());
 #endif
 
-#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   map.AddWebUIConfig(std::make_unique<UpdaterUIConfig>());
 #endif  // BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN)
 
@@ -514,7 +514,7 @@ void RegisterChromeWebUIConfigs() {
 #endif  // BUILDFLAG(IS_MAC)
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   map.AddWebUIConfig(std::make_unique<skills::SkillsUIConfig>());
 #endif  // BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
         // BUILDFLAG(IS_CHROMEOS)
