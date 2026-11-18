--- components/sync/base/features.cc.orig	2026-11-17 21:17:00 UTC
+++ components/sync/base/features.cc
@@ -80,7 +80,7 @@ BASE_FEATURE(kReplaceSyncPromosWithSignInPromos,
 );
 
 BASE_FEATURE(kReplaceSyncPromosWithSigninPromosNewSignin,
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
              base::FEATURE_ENABLED_BY_DEFAULT
 #else
              base::FEATURE_DISABLED_BY_DEFAULT
