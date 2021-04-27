--- chrome/common/chrome_features.cc.orig	2021-04-14 18:40:56 UTC
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
 
 #if BUILDFLAG(IS_CHROMEOS_ASH)
 // Enable Borealis on Chrome OS.
@@ -360,13 +360,13 @@ const base::Feature kEnableAllSystemWebApps{"EnableAll
 
 // TODO(crbug.com/1052397): Revisit the macro expression once build flag switch
 // of lacros-chrome is complete.
-#if defined(OS_WIN) || (defined(OS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS)) || \
+#if defined(OS_WIN) || (defined(OS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS)) || defined(OS_BSD) || \
     defined(OS_MAC)
 COMPONENT_EXPORT(CHROME_FEATURES)
 // Enables ephemeral Guest profiles on desktop.
 extern const base::Feature kEnableEphemeralGuestProfilesOnDesktop{
     "EnableEphemeralGuestProfilesOnDesktop", base::FEATURE_DISABLED_BY_DEFAULT};
-#endif  // defined(OS_WIN) || (defined(OS_LINUX) ||
+#endif  // defined(OS_WIN) || (defined(OS_LINUX) || defined(OS_BSD) ||
         // BUILDFLAG(IS_CHROMEOS_LACROS)) || defined(OS_MAC)
 
 #if defined(OS_WIN)
