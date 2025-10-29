--- chrome/browser/ui/startup/infobar_utils.cc.orig	2025-10-28 14:29:43 UTC
+++ chrome/browser/ui/startup/infobar_utils.cc
@@ -197,7 +197,7 @@ void AddInfoBarsIfNecessary(Browser* browser,
     }
 #endif
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
     if (base::FeatureList::IsEnabled(features::kSessionRestoreInfobar)) {
       // TODO(crbug.com/431828875): Instantiate and initialize the session
       // restore controller.
