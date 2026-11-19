--- components/sync/base/features.cc.orig	2026-11-19 12:25:27 UTC
+++ components/sync/base/features.cc
@@ -68,7 +68,7 @@ BASE_FEATURE(kReplaceSyncPromosWithSignInPromos,
 );
 
 bool IsReplaceSyncPromosWithSignInPromosEnabled() {
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
   return true;
 #else
   return base::FeatureList::IsEnabled(kReplaceSyncPromosWithSignInPromos);
