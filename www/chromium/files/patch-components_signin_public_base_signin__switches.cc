--- components/signin/public/base/signin_switches.cc.orig	2025-09-06 10:01:20 UTC
+++ components/signin/public/base/signin_switches.cc
@@ -73,7 +73,7 @@ BASE_FEATURE(kSmartEmailLineBreaking,
              base::FEATURE_ENABLED_BY_DEFAULT);
 #endif
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 // Enables the History Sync Opt-in on Desktop.
 BASE_FEATURE(kEnableHistorySyncOptin,
              "EnableHistorySyncOptin",
@@ -292,7 +292,7 @@ BASE_FEATURE(kSyncEnableBookmarksInTransportMode,
 #endif  // BUILDFLAG(IS_IOS)
 );
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 BASE_FEATURE(kSignInPromoMaterialNextUI,
              "SignInPromoMaterialNextUI",
              base::FEATURE_DISABLED_BY_DEFAULT);
