--- components/flags_ui/flags_state.cc.orig	2020-11-13 06:36:40 UTC
+++ components/flags_ui/flags_state.cc
@@ -687,7 +687,7 @@ int FlagsState::GetCurrentPlatform() {
   return kOsWin;
 #elif defined(OS_CHROMEOS)
   return kOsCrOS;
-#elif defined(OS_LINUX) || defined(OS_OPENBSD)
+#elif defined(OS_LINUX) || defined(OS_OPENBSD) || defined(OS_FREEBSD)
   return kOsLinux;
 #elif defined(OS_ANDROID)
   return kOsAndroid;
