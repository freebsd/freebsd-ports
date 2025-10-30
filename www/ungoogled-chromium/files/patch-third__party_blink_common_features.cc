--- third_party/blink/common/features.cc.orig	2025-11-01 06:40:37 UTC
+++ third_party/blink/common/features.cc
@@ -581,7 +581,7 @@ BASE_FEATURE_PARAM(base::TimeDelta,
 BASE_FEATURE(kDevToolsImprovedNetworkError, base::FEATURE_DISABLED_BY_DEFAULT);
 
 BASE_FEATURE(kDirectCompositorThreadIpc,
-#if BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC)
+#if BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_BSD)
              base::FEATURE_ENABLED_BY_DEFAULT
 #else
              base::FEATURE_DISABLED_BY_DEFAULT
