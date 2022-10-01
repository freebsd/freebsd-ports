--- components/flags_ui/flags_state.cc.orig	2022-10-01 07:40:07 UTC
+++ components/flags_ui/flags_state.cc
@@ -681,7 +681,7 @@ unsigned short FlagsState::GetCurrentPlatform() {
   return kOsCrOS;
 #elif BUILDFLAG(IS_CHROMEOS_LACROS)
   return kOsLacros;
-#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_OPENBSD)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   return kOsLinux;
 #elif BUILDFLAG(IS_ANDROID)
   return kOsAndroid;
