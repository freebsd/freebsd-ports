--- components/flags_ui/flags_state.cc.orig	2025-02-22 18:06:53 UTC
+++ components/flags_ui/flags_state.cc
@@ -751,7 +751,7 @@ unsigned short FlagsState::GetCurrentPlatform() {
   return kOsWin;
 #elif BUILDFLAG(IS_CHROMEOS)
   return kOsCrOS;
-#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_OPENBSD)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   return kOsLinux;
 #elif BUILDFLAG(IS_ANDROID)
   return kOsAndroid;
