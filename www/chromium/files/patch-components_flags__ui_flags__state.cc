--- components/flags_ui/flags_state.cc.orig	2024-07-30 11:12:21 UTC
+++ components/flags_ui/flags_state.cc
@@ -749,7 +749,7 @@ unsigned short FlagsState::GetCurrentPlatform() {
   return kOsCrOS;
 #elif BUILDFLAG(IS_CHROMEOS_LACROS)
   return kOsLacros;
-#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_OPENBSD)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   return kOsLinux;
 #elif BUILDFLAG(IS_ANDROID)
   return kOsAndroid;
