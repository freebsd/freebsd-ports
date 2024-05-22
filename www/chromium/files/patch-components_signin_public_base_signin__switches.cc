--- components/signin/public/base/signin_switches.cc.orig	2024-05-21 18:07:39 UTC
+++ components/signin/public/base/signin_switches.cc
@@ -145,7 +145,7 @@ bool IsExplicitBrowserSigninUIOnDesktopEnabled(
 }
 
 #if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN) || \
-    BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_IOS)
+    BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_IOS) || BUILDFLAG(IS_BSD)
 BASE_FEATURE(kMinorModeRestrictionsForHistorySyncOptIn,
              "MinorModeRestrictionsForHistorySyncOptIn",
              base::FEATURE_DISABLED_BY_DEFAULT);
@@ -154,7 +154,7 @@ constexpr int kMinorModeRestrictionsFetchDeadlineDefau
 #if BUILDFLAG(IS_ANDROID)
     // Based on Signin.AccountCapabilities.UserVisibleLatency
     400;
-#elif BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN)
+#elif BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
     // Based on Signin.SyncOptIn.PreSyncConfirmationLatency
     900;
 #elif BUILDFLAG(IS_IOS)
