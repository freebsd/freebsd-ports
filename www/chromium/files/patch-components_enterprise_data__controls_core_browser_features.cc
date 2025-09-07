--- components/enterprise/data_controls/core/browser/features.cc.orig	2025-09-06 10:01:20 UTC
+++ components/enterprise/data_controls/core/browser/features.cc
@@ -13,7 +13,7 @@ BASE_FEATURE(kEnableClipboardDataControlsAndroid,
 #endif
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 BASE_FEATURE(kEnableDownloadDataControlsDesktop,
              "EnableDownloadDataControlsDesktop",
              base::FEATURE_DISABLED_BY_DEFAULT);
