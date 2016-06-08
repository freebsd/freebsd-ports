--- chrome/common/chrome_switches.cc.orig	2016-05-25 15:00:58.000000000 -0400
+++ chrome/common/chrome_switches.cc	2016-05-27 09:57:28.188798000 -0400
@@ -1298,7 +1298,7 @@
     "tab-management-experiment-type-elderberry";
 #endif  // defined(OS_ANDROID)
 
-#if defined(OS_WIN) || defined(OS_LINUX)
+#if defined(OS_WIN) || defined(OS_LINUX) || defined(OS_BSD)
 extern const char kEnableInputImeAPI[] = "enable-input-ime-api";
 extern const char kDisableInputImeAPI[] = "disable-input-ime-api";
 #endif
