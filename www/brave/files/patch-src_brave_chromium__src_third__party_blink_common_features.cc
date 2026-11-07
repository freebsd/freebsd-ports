--- src/brave/chromium_src/third_party/blink/common/features.cc.orig	2026-06-01 00:00:00 UTC
+++ src/brave/chromium_src/third_party/blink/common/features.cc
@@ -44,7 +44,7 @@
 
 // Enables protection against fingerprinting on screen dimensions.
 BASE_FEATURE(kBraveBlockScreenFingerprinting,
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD))
              base::FEATURE_ENABLED_BY_DEFAULT
 #else
              base::FEATURE_DISABLED_BY_DEFAULT
@@ -71,16 +71,16 @@
 #endif
 );
 
-#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_MAC) || (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD))
 BASE_FEATURE(kMiddleButtonClickAutoscroll,
              "MiddelButtonClickAutoscroll",
              base::FEATURE_DISABLED_BY_DEFAULT);
-#endif  // BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#endif  // BUILDFLAG(IS_MAC) || (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD))
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC)
+#if BUILDFLAG(IS_WIN) || (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)) || BUILDFLAG(IS_MAC)
 BASE_FEATURE(kForceContextMenuOnShiftRightClick,
              base::FEATURE_ENABLED_BY_DEFAULT);
-#endif  // BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC)
+#endif  // BUILDFLAG(IS_WIN) || (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)) || BUILDFLAG(IS_MAC)
 
 bool IsPrerender2Enabled() {
   return false;
