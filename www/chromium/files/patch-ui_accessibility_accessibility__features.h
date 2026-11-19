--- ui/accessibility/accessibility_features.h.orig	2026-11-19 12:25:27 UTC
+++ ui/accessibility/accessibility_features.h
@@ -391,7 +391,7 @@ AX_BASE_EXPORT BASE_DECLARE_FEATURE(kMacAccessibilityT
 AX_BASE_EXPORT bool IsMacAccessibilityTextOperationEnabled();
 #endif  // BUILDFLAG(IS_MAC)
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 // Disable the wasm tts engine component to use dev version local extension
 // files.
 AX_BASE_EXPORT BASE_DECLARE_FEATURE(kWasmTtsEngineAutoInstallDisabled);
