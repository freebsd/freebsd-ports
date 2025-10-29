--- third_party/blink/common/features.cc.orig	2025-10-28 14:29:43 UTC
+++ third_party/blink/common/features.cc
@@ -572,7 +572,7 @@ BASE_FEATURE_PARAM(base::TimeDelta,
 BASE_FEATURE(DevToolsImprovedNetworkError, base::FEATURE_DISABLED_BY_DEFAULT);
 
 BASE_FEATURE(DirectCompositorThreadIpc,
-#if BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC)
+#if BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_BSD)
              base::FEATURE_ENABLED_BY_DEFAULT
 #else
              base::FEATURE_DISABLED_BY_DEFAULT
