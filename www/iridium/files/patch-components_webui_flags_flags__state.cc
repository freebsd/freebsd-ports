--- components/webui/flags/flags_state.cc.orig	2026-02-16 10:45:29 UTC
+++ components/webui/flags/flags_state.cc
@@ -778,7 +778,7 @@ unsigned short FlagsState::GetCurrentPlatform() {
   return kOsWin;
 #elif BUILDFLAG(IS_CHROMEOS)
   return kOsCrOS;
-#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_OPENBSD)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   return kOsLinux;
 #elif BUILDFLAG(IS_ANDROID)
   return kOsAndroid;
