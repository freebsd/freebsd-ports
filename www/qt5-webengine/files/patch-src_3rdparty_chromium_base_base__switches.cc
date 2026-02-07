--- src/3rdparty/chromium/base/base_switches.cc.orig	2021-12-15 16:12:54 UTC
+++ src/3rdparty/chromium/base/base_switches.cc
@@ -117,7 +117,7 @@ const char kDisableUsbKeyboardDetect[]      = "disable
 const char kDisableUsbKeyboardDetect[]      = "disable-usb-keyboard-detect";
 #endif
 
-#if defined(OS_LINUX) && !defined(OS_CHROMEOS) && !BUILDFLAG(IS_LACROS)
+#if (defined(OS_LINUX) && !defined(OS_CHROMEOS) && !BUILDFLAG(IS_LACROS)) || defined(OS_BSD)
 // The /dev/shm partition is too small in certain VM environments, causing
 // Chrome to fail or crash (see http://crbug.com/715363). Use this flag to
 // work-around this issue (a temporary directory will always be used to create
@@ -152,7 +152,7 @@ const char kForceFieldTrialParams[] = "force-fieldtria
 
 #endif
 
-#if defined(OS_LINUX) || defined(OS_CHROMEOS)
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
 // Controls whether or not retired instruction counts are surfaced for threads
 // in trace events on Linux.
 //
