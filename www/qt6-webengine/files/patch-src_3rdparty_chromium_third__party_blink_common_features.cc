--- src/3rdparty/chromium/third_party/blink/common/features.cc.orig	2026-08-11 12:42:19 UTC
+++ src/3rdparty/chromium/third_party/blink/common/features.cc
@@ -695,7 +695,7 @@ BASE_FEATURE(kDevToolsImprovedNetworkError,
              "DevToolsImprovedNetworkError",
              base::FEATURE_DISABLED_BY_DEFAULT);
 
-#if BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC)
+#if BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_BSD)
 BASE_FEATURE(kDirectCompositorThreadIpc,
              "DirectCompositorThreadIpc",
              base::FEATURE_ENABLED_BY_DEFAULT);
