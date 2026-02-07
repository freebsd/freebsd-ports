--- src/3rdparty/chromium/base/base_switches.h.orig	2021-12-15 16:12:54 UTC
+++ src/3rdparty/chromium/base/base_switches.h
@@ -39,7 +39,7 @@ extern const char kDisableUsbKeyboardDetect[];
 extern const char kDisableUsbKeyboardDetect[];
 #endif
 
-#if defined(OS_LINUX) && !defined(OS_CHROMEOS) && !BUILDFLAG(IS_LACROS)
+#if (defined(OS_LINUX) && !defined(OS_CHROMEOS) && !BUILDFLAG(IS_LACROS)) || defined(OS_BSD)
 extern const char kDisableDevShmUsage[];
 #endif
 
@@ -55,7 +55,7 @@ extern const char kForceFieldTrialParams[];
 extern const char kForceFieldTrialParams[];
 #endif
 
-#if defined(OS_LINUX) || defined(OS_CHROMEOS)
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
 extern const char kEnableThreadInstructionCount[];
 #endif
 
