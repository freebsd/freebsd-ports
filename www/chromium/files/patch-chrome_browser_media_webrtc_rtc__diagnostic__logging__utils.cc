--- chrome/browser/media/webrtc/rtc_diagnostic_logging_utils.cc.orig	2026-04-09 06:05:42 UTC
+++ chrome/browser/media/webrtc/rtc_diagnostic_logging_utils.cc
@@ -22,7 +22,7 @@
 #include "url/origin.h"
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 #define WEBRTC_DIAGNOSTIC_LOGGING_SUPPORTED 1
 #else
 #define WEBRTC_DIAGNOSTIC_LOGGING_SUPPORTED 0
