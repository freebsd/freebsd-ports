--- components/flags_ui/flags_state.cc.orig	2021-09-24 04:26:03 UTC
+++ components/flags_ui/flags_state.cc
@@ -642,7 +642,7 @@ unsigned short FlagsState::GetCurrentPlatform() {
   return kOsWin;
 #elif BUILDFLAG(IS_CHROMEOS_ASH)
   return kOsCrOS;
-#elif (defined(OS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS)) || \
+#elif (defined(OS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS)) || defined(OS_FREEBSD) || \
     defined(OS_OPENBSD)
   return kOsLinux;
 #elif defined(OS_ANDROID)
