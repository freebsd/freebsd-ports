--- chrome/browser/extensions/component_extensions_allowlist/allowlist.cc.orig	2026-11-11 14:44:17 UTC
+++ chrome/browser/extensions/component_extensions_allowlist/allowlist.cc
@@ -55,7 +55,7 @@ bool IsComponentExtensionAllowlisted(const std::string
       extension_misc::kQuickOfficeComponentExtensionId,
 #endif  // BUILDFLAG(GOOGLE_CHROME_BRANDING)
 #endif  // BUILDFLAG(IS_CHROMEOS)
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_BSD)
       extension_misc::kTTSEngineExtensionId,
       extension_misc::kComponentUpdaterTTSEngineExtensionId,
 #endif  // BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC)
