--- chrome/common/chrome_features.h.orig	2020-11-13 06:36:38 UTC
+++ chrome/common/chrome_features.h
@@ -82,10 +82,10 @@ extern const base::Feature kAppShimNewCloseBehavior;
 
 COMPONENT_EXPORT(CHROME_FEATURES) extern const base::Feature kAsyncDns;
 
-#if defined(OS_WIN) || defined(OS_LINUX) || defined(OS_CHROMEOS)
+#if defined(OS_WIN) || defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
 COMPONENT_EXPORT(CHROME_FEATURES)
 extern const base::Feature kBackgroundModeAllowRestart;
-#endif  // defined(OS_WIN) || defined(OS_LINUX) || defined(OS_CHROMEOS)
+#endif  // defined(OS_WIN) || defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
 
 #if defined(OS_CHROMEOS)
 COMPONENT_EXPORT(CHROME_FEATURES) extern const base::Feature kBorealis;
@@ -214,10 +214,10 @@ extern const base::Feature kEnableAmbientAuthenticatio
 COMPONENT_EXPORT(CHROME_FEATURES)
 extern const base::Feature kEnableAmbientAuthenticationInIncognito;
 
-#if defined(OS_WIN) || defined(OS_LINUX) || defined(OS_MAC)
+#if defined(OS_WIN) || defined(OS_LINUX) || defined(OS_MAC) || defined(OS_BSD)
 COMPONENT_EXPORT(CHROME_FEATURES)
 extern const base::Feature kEnableEphemeralGuestProfilesOnDesktop;
-#endif  // defined(OS_WIN) || defined(OS_LINUX) || defined(OS_MAC)
+#endif  // defined(OS_WIN) || defined(OS_LINUX) || defined(OS_MAC) || defined(OS_BSD)
 
 #if defined(OS_WIN)
 COMPONENT_EXPORT(CHROME_FEATURES)
