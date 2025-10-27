--- components/signin/public/base/signin_switches.cc.orig	2025-10-21 16:57:35 UTC
+++ components/signin/public/base/signin_switches.cc
@@ -72,7 +72,7 @@ BASE_FEATURE(kSupportWebSigninAddSession,
              base::FEATURE_ENABLED_BY_DEFAULT);
 #endif  // BUILDFLAG(IS_ANDROID)
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 // Enables the History Sync Opt-in on Desktop.
 BASE_FEATURE(kEnableHistorySyncOptin,
              "EnableHistorySyncOptin",
@@ -282,7 +282,7 @@ BASE_FEATURE(kSyncEnableBookmarksInTransportMode,
 #endif  // BUILDFLAG(IS_IOS)
 );
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 BASE_FEATURE(kSignInPromoMaterialNextUI,
              "SignInPromoMaterialNextUI",
              base::FEATURE_DISABLED_BY_DEFAULT);
