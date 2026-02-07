--- src/3rdparty/chromium/ui/accessibility/accessibility_features.cc.orig	2025-08-15 18:30:00 UTC
+++ src/3rdparty/chromium/ui/accessibility/accessibility_features.cc
@@ -403,7 +403,7 @@ bool IsBlockRootWindowAccessibleNameChangeEventEnabled
 }
 #endif  // BUILDFLAG(IS_MAC)
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 BASE_FEATURE(kWasmTtsComponentUpdaterEnabled,
              "WasmTtsComponentUpdaterEnabled",
              base::FEATURE_DISABLED_BY_DEFAULT);
