--- src/3rdparty/chromium/components/flags_ui/flags_state.cc.orig	2021-12-15 16:12:54 UTC
+++ src/3rdparty/chromium/components/flags_ui/flags_state.cc
@@ -687,7 +687,7 @@ int FlagsState::GetCurrentPlatform() {
   return kOsWin;
 #elif defined(OS_CHROMEOS)
   return kOsCrOS;
-#elif defined(OS_LINUX) || defined(OS_OPENBSD)
+#elif defined(OS_LINUX) || defined(OS_OPENBSD) || defined(OS_FREEBSD)
   return kOsLinux;
 #elif defined(OS_ANDROID)
   return kOsAndroid;
