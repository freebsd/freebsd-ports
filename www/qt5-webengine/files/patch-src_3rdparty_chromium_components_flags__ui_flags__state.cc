--- src/3rdparty/chromium/components/flags_ui/flags_state.cc.orig	2017-01-26 00:49:11 UTC
+++ src/3rdparty/chromium/components/flags_ui/flags_state.cc
@@ -544,7 +544,7 @@ int FlagsState::GetCurrentPlatform() {
   return kOsWin;
 #elif defined(OS_CHROMEOS)  // Needs to be before the OS_LINUX check.
   return kOsCrOS;
-#elif defined(OS_LINUX) || defined(OS_OPENBSD)
+#elif defined(OS_LINUX) || defined(OS_OPENBSD) || defined(OS_FREEBSD)
   return kOsLinux;
 #elif defined(OS_ANDROID)
   return kOsAndroid;
