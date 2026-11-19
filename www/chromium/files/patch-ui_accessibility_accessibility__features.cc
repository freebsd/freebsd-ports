--- ui/accessibility/accessibility_features.cc.orig	2026-11-19 12:25:27 UTC
+++ ui/accessibility/accessibility_features.cc
@@ -467,7 +467,7 @@ bool IsMacAccessibilityTextOperationEnabled() {
 }
 #endif  // BUILDFLAG(IS_MAC)
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 BASE_FEATURE(kWasmTtsEngineAutoInstallDisabled,
              base::FEATURE_DISABLED_BY_DEFAULT);
 bool IsWasmTtsEngineAutoInstallDisabled() {
