--- components/flags_ui/flags_state.cc.orig	2017-04-19 19:06:32 UTC
+++ components/flags_ui/flags_state.cc
@@ -566,7 +566,7 @@ int FlagsState::GetCurrentPlatform() {
   return kOsWin;
 #elif defined(OS_CHROMEOS)  // Needs to be before the OS_LINUX check.
   return kOsCrOS;
-#elif defined(OS_LINUX) || defined(OS_OPENBSD)
+#elif defined(OS_LINUX) || defined(OS_OPENBSD) || defined(OS_FREEBSD)
   return kOsLinux;
 #elif defined(OS_ANDROID)
   return kOsAndroid;
