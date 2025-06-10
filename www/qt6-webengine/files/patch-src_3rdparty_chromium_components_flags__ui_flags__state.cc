--- src/3rdparty/chromium/components/flags_ui/flags_state.cc.orig	2024-09-30 07:45:04 UTC
+++ src/3rdparty/chromium/components/flags_ui/flags_state.cc
@@ -755,7 +755,7 @@ unsigned short FlagsState::GetCurrentPlatform() {
   return kOsCrOS;
 #elif BUILDFLAG(IS_CHROMEOS_LACROS)
   return kOsLacros;
-#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_OPENBSD)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   return kOsLinux;
 #elif BUILDFLAG(IS_ANDROID)
   return kOsAndroid;
