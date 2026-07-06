--- chrome/browser/media/webrtc/rtc_diagnostic_logging_utils.cc.orig	2026-06-05 13:45:06 UTC
+++ chrome/browser/media/webrtc/rtc_diagnostic_logging_utils.cc
@@ -32,7 +32,7 @@
 #include "url/origin.h"
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 #define WEBRTC_DIAGNOSTIC_LOGGING_SUPPORTED 1
 #else
 #define WEBRTC_DIAGNOSTIC_LOGGING_SUPPORTED 0
