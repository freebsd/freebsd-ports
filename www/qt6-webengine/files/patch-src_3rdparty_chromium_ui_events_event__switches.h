--- src/3rdparty/chromium/ui/events/event_switches.h.orig	2022-09-26 10:05:50 UTC
+++ src/3rdparty/chromium/ui/events/event_switches.h
@@ -12,7 +12,7 @@ EVENTS_BASE_EXPORT extern const char kCompensateForUns
 
 EVENTS_BASE_EXPORT extern const char kCompensateForUnstablePinchZoom[];
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 EVENTS_BASE_EXPORT extern const char kTouchDevices[];
 EVENTS_BASE_EXPORT extern const char kPenDevices[];
 #endif
