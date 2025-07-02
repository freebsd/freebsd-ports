--- ui/accessibility/accessibility_features.cc.orig	2025-07-02 06:08:04 UTC
+++ ui/accessibility/accessibility_features.cc
@@ -524,7 +524,7 @@ bool IsBlockRootWindowAccessibleNameChangeEventEnabled
 }
 #endif  // BUILDFLAG(IS_MAC)
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 BASE_FEATURE(kWasmTtsComponentUpdaterEnabled,
              "WasmTtsComponentUpdaterEnabled",
              base::FEATURE_ENABLED_BY_DEFAULT);
