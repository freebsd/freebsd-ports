--- components/signin/public/base/signin_switches.cc.orig	2024-07-31 14:19:23 UTC
+++ components/signin/public/base/signin_switches.cc
@@ -123,11 +123,11 @@ bool IsExplicitBrowserSigninUIOnDesktopEnabled() {
 }
 
 #if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN) || \
-    BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_IOS)
+    BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_IOS) || BUILDFLAG(IS_BSD)
 
 // Desktop and Android are being launched (enabled by default), iOS is pending.
 #if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN) || \
-    BUILDFLAG(IS_ANDROID)
+    BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_BSD)
 #define MINOR_MODE_FEATURE_DEFAULT_STATUS base::FEATURE_ENABLED_BY_DEFAULT
 #else
 #define MINOR_MODE_FEATURE_DEFAULT_STATUS base::FEATURE_DISABLED_BY_DEFAULT
@@ -141,7 +141,7 @@ constexpr int kMinorModeRestrictionsFetchDeadlineDefau
 #if BUILDFLAG(IS_ANDROID)
     // Based on Signin.AccountCapabilities.UserVisibleLatency
     1000;
-#elif BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN)
+#elif BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
     // Based on Signin.SyncOptIn.PreSyncConfirmationLatency
     1000;
 #elif BUILDFLAG(IS_IOS)
