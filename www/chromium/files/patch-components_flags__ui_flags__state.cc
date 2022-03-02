--- components/flags_ui/flags_state.cc.orig	2022-02-28 16:54:41 UTC
+++ components/flags_ui/flags_state.cc
@@ -654,7 +654,7 @@ unsigned short FlagsState::GetCurrentPlatform() {
 #elif BUILDFLAG(IS_CHROMEOS_ASH)
   return kOsCrOS;
 #elif (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS)) || \
-    BUILDFLAG(IS_OPENBSD)
+    BUILDFLAG(IS_BSD)
   return kOsLinux;
 #elif BUILDFLAG(IS_ANDROID)
   return kOsAndroid;
