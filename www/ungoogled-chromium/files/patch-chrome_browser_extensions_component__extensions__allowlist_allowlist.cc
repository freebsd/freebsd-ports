--- chrome/browser/extensions/component_extensions_allowlist/allowlist.cc.orig	2026-11-17 11:49:09 UTC
+++ chrome/browser/extensions/component_extensions_allowlist/allowlist.cc
@@ -54,7 +54,7 @@ bool IsComponentExtensionAllowlisted(const std::string
       extension_misc::kQuickOfficeComponentExtensionId,
 #endif  // BUILDFLAG(GOOGLE_CHROME_BRANDING)
 #endif  // BUILDFLAG(IS_CHROMEOS)
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_BSD)
       extension_misc::kTTSEngineExtensionId,
       extension_misc::kComponentUpdaterTTSEngineExtensionId,
 #endif  // BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC)
