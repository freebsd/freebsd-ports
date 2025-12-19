--- src/3rdparty/chromium/chrome/common/extensions/extension_constants.cc.orig	2025-08-15 18:30:00 UTC
+++ src/3rdparty/chromium/chrome/common/extensions/extension_constants.cc
@@ -46,7 +46,7 @@ const char* const kBuiltInFirstPartyExtensionIds[] = {
 #if !BUILDFLAG(IS_CHROMEOS_LACROS)
     kReadingModeGDocsHelperExtensionId,
 #endif        // !BUILDFLAG(IS_CHROMEOS_LACROS)
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_BSD)
     kTTSEngineExtensionId,
     kComponentUpdaterTTSEngineExtensionId,
 #endif        // BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC)
