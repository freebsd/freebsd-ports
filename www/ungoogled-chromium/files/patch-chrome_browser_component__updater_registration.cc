--- chrome/browser/component_updater/registration.cc.orig	2026-02-15 10:01:45 UTC
+++ chrome/browser/component_updater/registration.cc
@@ -88,7 +88,7 @@
 #endif  // BUILDFLAG(ENABLE_WIDEVINE_CDM_COMPONENT)
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_BSD)
 #include "components/component_updater/installer_policies/amount_extraction_heuristic_regexes_component_installer.h"
 #endif  // BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) ||
         // BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID)
@@ -101,7 +101,7 @@
 #include "chrome/browser/component_updater/lacros_component_remover.h"
 #endif  // BUILDFLAG(IS_CHROMEOS)
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "chrome/browser/component_updater/wasm_tts_engine_component_installer.h"
 #endif  // BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
 
@@ -234,12 +234,12 @@ void RegisterComponentsForUpdate() {
 #endif  // BUILDFLAG(ENABLE_ON_DEVICE_TRANSLATION)
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_BSD)
   RegisterAmountExtractionHeuristicRegexesComponent(cus);
 #endif  // BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) ||
         // BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID)
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   RegisterWasmTtsEngineComponent(cus, g_browser_process->local_state());
 #endif  // BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
 }
