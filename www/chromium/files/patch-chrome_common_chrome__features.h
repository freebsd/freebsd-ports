--- chrome/common/chrome_features.h.orig	2021-07-19 18:45:10 UTC
+++ chrome/common/chrome_features.h
@@ -69,10 +69,10 @@ extern const base::Feature kAppShimNewCloseBehavior;
 
 COMPONENT_EXPORT(CHROME_FEATURES) extern const base::Feature kAsyncDns;
 
-#if defined(OS_WIN) || defined(OS_LINUX) || defined(OS_CHROMEOS)
+#if defined(OS_WIN) || defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
 COMPONENT_EXPORT(CHROME_FEATURES)
 extern const base::Feature kBackgroundModeAllowRestart;
-#endif  // defined(OS_WIN) || defined(OS_LINUX) || defined(OS_CHROMEOS)
+#endif  // defined(OS_WIN) || defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
 
 #if BUILDFLAG(IS_CHROMEOS_ASH)
 COMPONENT_EXPORT(CHROME_FEATURES) extern const base::Feature kBorealis;
@@ -250,11 +250,11 @@ extern const base::Feature kEnableAmbientAuthenticatio
 
 // TODO(crbug.com/1052397): Revisit the macro expression once build flag switch
 // of lacros-chrome is complete.
-#if defined(OS_WIN) || (defined(OS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS)) || \
+#if defined(OS_WIN) || (defined(OS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS)) || defined(OS_BSD) || \
     defined(OS_MAC)
 COMPONENT_EXPORT(CHROME_FEATURES)
 extern const base::Feature kEnableEphemeralGuestProfilesOnDesktop;
-#endif  // defined(OS_WIN) || (defined(OS_LINUX) ||
+#endif  // defined(OS_WIN) || (defined(OS_LINUX) || defined(OS_BSD) ||
         // BUILDFLAG(IS_CHROMEOS_LACROS)) ||  defined(OS_MAC)
 
 #if defined(OS_WIN)
@@ -374,7 +374,7 @@ COMPONENT_EXPORT(CHROME_FEATURES)
 extern const base::Feature kIncognitoBrandConsistencyForAndroid;
 #endif
 
-#if defined(OS_MAC) || defined(OS_WIN) || defined(OS_LINUX) || \
+#if defined(OS_MAC) || defined(OS_WIN) || defined(OS_LINUX) || defined(OS_BSD) || \
     defined(OS_CHROMEOS)
 COMPONENT_EXPORT(CHROME_FEATURES)
 extern const base::Feature kIncognitoBrandConsistencyForDesktop;
