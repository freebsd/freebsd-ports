--- chrome/browser/component_updater/registration.cc.orig	2024-11-16 12:20:41 UTC
+++ chrome/browser/component_updater/registration.cc
@@ -80,7 +80,7 @@
 #include "media/base/media_switches.h"
 #endif  // !BUILDFLAG(IS_ANDROID)
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "chrome/browser/component_updater/translate_kit_component_installer.h"
 #include "chrome/browser/component_updater/translate_kit_language_pack_component_installer.h"
 #endif  // BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
@@ -227,7 +227,7 @@ void RegisterComponentsForUpdate() {
 
   RegisterPlusAddressBlocklistComponent(cus);
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   // TODO(crbug.com/364795294): Support other platforms.
   RegisterTranslateKitComponent(cus, g_browser_process->local_state(),
                                 /*force_install=*/false,
