--- components/signin/public/base/signin_switches.cc.orig	2025-05-05 10:57:53 UTC
+++ components/signin/public/base/signin_switches.cc
@@ -55,7 +55,7 @@ BASE_FEATURE(kUseHostedDomainForManagementCheckOnSigni
              base::FEATURE_DISABLED_BY_DEFAULT);
 #endif
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 // Enables the History Sync Opt-in on Desktop.
 BASE_FEATURE(kEnableHistorySyncOptin,
              "EnableHistorySyncOptin",
