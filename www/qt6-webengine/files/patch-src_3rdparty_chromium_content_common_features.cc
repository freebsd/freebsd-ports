--- src/3rdparty/chromium/content/common/features.cc.orig	2026-02-26 14:39:03 UTC
+++ src/3rdparty/chromium/content/common/features.cc
@@ -172,7 +172,7 @@ BASE_FEATURE(kEmbeddingRequiresOptIn,
              base::FEATURE_DISABLED_BY_DEFAULT);
 
 // Enables error reporting for JS errors inside DevTools frontend host
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 BASE_FEATURE(kEnableDevToolsJsErrorReporting,
              "EnableDevToolsJsErrorReporting",
              base::FEATURE_DISABLED_BY_DEFAULT);
