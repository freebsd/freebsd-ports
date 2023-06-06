--- components/flags_ui/flags_state.cc.orig	2023-06-05 19:39:05 UTC
+++ components/flags_ui/flags_state.cc
@@ -682,7 +682,7 @@ unsigned short FlagsState::GetCurrentPlatform() {
   return kOsCrOS;
 #elif BUILDFLAG(IS_CHROMEOS_LACROS)
   return kOsLacros;
-#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_OPENBSD)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   return kOsLinux;
 #elif BUILDFLAG(IS_ANDROID)
   return kOsAndroid;
