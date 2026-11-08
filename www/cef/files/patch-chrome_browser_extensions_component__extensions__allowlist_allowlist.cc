--- chrome/browser/extensions/component_extensions_allowlist/allowlist.cc.orig	2026-08-12 09:02:10 UTC
+++ chrome/browser/extensions/component_extensions_allowlist/allowlist.cc
@@ -55,7 +55,7 @@ bool IsComponentExtensionAllowlisted(const std::string
 #endif  // BUILDFLAG(GOOGLE_CHROME_BRANDING)
 #endif  // BUILDFLAG(IS_CHROMEOS)
       extension_misc::kReadingModeGDocsHelperExtensionId,
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_BSD)
       extension_misc::kTTSEngineExtensionId,
       extension_misc::kComponentUpdaterTTSEngineExtensionId,
 #endif  // BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC)
