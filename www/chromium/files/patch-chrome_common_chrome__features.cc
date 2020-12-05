--- chrome/common/chrome_features.cc.orig	2020-11-13 06:36:38 UTC
+++ chrome/common/chrome_features.cc
@@ -96,13 +96,13 @@ const base::Feature kAsyncDns {
 #endif
 };
 
-#if defined(OS_WIN) || defined(OS_LINUX) || defined(OS_CHROMEOS)
+#if defined(OS_WIN) || defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
 // Enables the Restart background mode optimization. When all Chrome UI is
 // closed and it goes in the background, allows to restart the browser to
 // discard memory.
 const base::Feature kBackgroundModeAllowRestart{
     "BackgroundModeAllowRestart", base::FEATURE_DISABLED_BY_DEFAULT};
-#endif  // defined(OS_WIN) || defined(OS_LINUX) || defined(OS_CHROMEOS)
+#endif  // defined(OS_WIN) || defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
 
 #if defined(OS_CHROMEOS)
 // Enable Borealis on Chrome OS.
@@ -337,12 +337,12 @@ const base::Feature kEnableAmbientAuthenticationInInco
     "EnableAmbientAuthenticationInIncognito",
     base::FEATURE_DISABLED_BY_DEFAULT};
 
-#if defined(OS_WIN) || defined(OS_LINUX) || defined(OS_MAC)
+#if defined(OS_WIN) || defined(OS_LINUX) || defined(OS_MAC) || defined(OS_BSD)
 COMPONENT_EXPORT(CHROME_FEATURES)
 // Enables ephemeral Guest profiles on desktop.
 extern const base::Feature kEnableEphemeralGuestProfilesOnDesktop{
     "EnableEphemeralGuestProfilesOnDesktop", base::FEATURE_DISABLED_BY_DEFAULT};
-#endif  // defined(OS_WIN) || defined(OS_LINUX) || defined(OS_MAC)
+#endif  // defined(OS_WIN) || defined(OS_LINUX) || defined(OS_MAC) || defined(OS_BSD)
 
 #if defined(OS_WIN)
 // Enables users to create a desktop shortcut for incognito mode.
