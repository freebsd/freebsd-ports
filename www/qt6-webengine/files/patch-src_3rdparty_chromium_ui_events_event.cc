--- src/3rdparty/chromium/ui/events/event.cc.orig	2022-09-26 10:05:50 UTC
+++ src/3rdparty/chromium/ui/events/event.cc
@@ -453,7 +453,7 @@ MouseEvent::MouseEvent(const PlatformEvent& native_eve
 MouseEvent::MouseEvent(const PlatformEvent& native_event)
     : LocatedEvent(native_event),
       changed_button_flags_(GetChangedMouseButtonFlagsFromNative(native_event)),
-#if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
       movement_(GetMouseMovementFromNative(native_event)),
 #endif
       pointer_details_(GetMousePointerDetailsFromNative(native_event)) {
@@ -935,7 +935,7 @@ void KeyEvent::InitializeNative() {
   if (synthesize_key_repeat_enabled_ && IsRepeated(GetLastKeyEvent()))
     set_flags(flags() | EF_IS_REPEAT);
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   NormalizeFlags();
 #elif BUILDFLAG(IS_WIN)
   // Only Windows has native character events.
