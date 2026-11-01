--- components/webui/flags/flags_state.cc.orig	2026-10-31 12:09:36 UTC
+++ components/webui/flags/flags_state.cc
@@ -803,7 +803,7 @@ unsigned short FlagsState::GetCurrentPlatform() {
   return kOsWin;
 #elif BUILDFLAG(IS_CHROMEOS)
   return kOsCrOS;
-#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_OPENBSD)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   return kOsLinux;
 #elif BUILDFLAG(IS_ANDROID)
   return kOsAndroid;
