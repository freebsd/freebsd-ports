--- ui/accessibility/accessibility_features.cc.orig	2025-09-06 10:01:20 UTC
+++ ui/accessibility/accessibility_features.cc
@@ -507,7 +507,7 @@ bool IsScreenAITestModeEnabled() {
   return base::FeatureList::IsEnabled(::features::kScreenAITestMode);
 }
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 BASE_FEATURE(kScreenAIPartitionAllocAdvancedChecksEnabled,
              "ScreenAIPartitionAllocAdvancedChecksEnabled",
              base::FEATURE_DISABLED_BY_DEFAULT);
@@ -549,7 +549,7 @@ bool IsBlockRootWindowAccessibleNameChangeEventEnabled
 }
 #endif  // BUILDFLAG(IS_MAC)
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 BASE_FEATURE(kWasmTtsComponentUpdaterV3Enabled,
              "WasmTtsComponentUpdaterV3Enabled",
              base::FEATURE_DISABLED_BY_DEFAULT);
