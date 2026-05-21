--- src/3rdparty/chromium/third_party/blink/common/features.cc.orig	2026-02-26 14:39:03 UTC
+++ src/3rdparty/chromium/third_party/blink/common/features.cc
@@ -684,7 +684,7 @@ BASE_FEATURE(kDevToolsImprovedNetworkError,
              "DevToolsImprovedNetworkError",
              base::FEATURE_DISABLED_BY_DEFAULT);
 
-#if BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC)
+#if BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_BSD)
 BASE_FEATURE(kDirectCompositorThreadIpc,
              "DirectCompositorThreadIpc",
              base::FEATURE_ENABLED_BY_DEFAULT);
