--- components/flags_ui/flags_state.cc.orig	2016-03-04 21:01:15.539156962 +0100
+++ components/flags_ui/flags_state.cc	2016-03-04 21:00:48.239033063 +0100
@@ -450,7 +450,7 @@
   return kOsWin;
 #elif defined(OS_CHROMEOS)  // Needs to be before the OS_LINUX check.
   return kOsCrOS;
-#elif defined(OS_LINUX) || defined(OS_OPENBSD)
+#elif defined(OS_LINUX) || defined(OS_OPENBSD) || defined(OS_FREEBSD)
   return kOsLinux;
 #elif defined(OS_ANDROID)
   return kOsAndroid;
