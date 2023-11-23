--- src/3rdparty/chromium/content/browser/renderer_host/back_forward_cache_impl.cc.orig	2023-03-09 06:31:50 UTC
+++ src/3rdparty/chromium/content/browser/renderer_host/back_forward_cache_impl.cc
@@ -56,7 +56,7 @@ BASE_FEATURE(kBackForwardCacheSize,
 // Sets the BackForwardCache size for desktop.
 // See crbug.com/1291435.
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
              base::FEATURE_ENABLED_BY_DEFAULT
 #else
              base::FEATURE_DISABLED_BY_DEFAULT
