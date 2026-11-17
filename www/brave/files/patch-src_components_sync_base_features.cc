--- src/components/sync/base/features.cc.orig	2026-10-18 18:43:23 UTC
+++ src/components/sync/base/features.cc
@@ -83,7 +83,7 @@ BASE_FEATURE(kReplaceSyncPromosWithSignI
 );
 
 BASE_FEATURE(kReplaceSyncPromosWithSigninPromosNewSignin,
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
              base::FEATURE_ENABLED_BY_DEFAULT
 #else
              base::FEATURE_DISABLED_BY_DEFAULT
