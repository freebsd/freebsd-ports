--- ui/accessibility/accessibility_features.h.orig	2025-07-02 06:08:04 UTC
+++ ui/accessibility/accessibility_features.h
@@ -347,7 +347,7 @@ AX_BASE_EXPORT BASE_DECLARE_FEATURE(kBlockRootWindowAc
 AX_BASE_EXPORT bool IsBlockRootWindowAccessibleNameChangeEventEnabled();
 #endif  // BUILDFLAG(IS_MAC)
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 // Enable the component updater to download the wasm tts engine component.
 AX_BASE_EXPORT BASE_DECLARE_FEATURE(kWasmTtsComponentUpdaterEnabled);
 AX_BASE_EXPORT bool IsWasmTtsComponentUpdaterEnabled();
