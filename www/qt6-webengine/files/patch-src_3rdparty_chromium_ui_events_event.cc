--- src/3rdparty/chromium/ui/events/event.cc.orig	2024-09-30 07:45:04 UTC
+++ src/3rdparty/chromium/ui/events/event.cc
@@ -366,7 +366,7 @@ std::string LocatedEvent::ToString() const {
 MouseEvent::MouseEvent(const PlatformEvent& native_event)
     : LocatedEvent(native_event),
       changed_button_flags_(GetChangedMouseButtonFlagsFromNative(native_event)),
-#if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
       movement_(GetMouseMovementFromNative(native_event)),
 #endif
       pointer_details_(GetMousePointerDetailsFromNative(native_event)) {
@@ -622,7 +622,7 @@ std::unique_ptr<Event> MouseWheelEvent::Clone() const 
   return std::make_unique<MouseWheelEvent>(*this);
 }
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_FUCHSIA) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_FUCHSIA) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 // This value matches Windows, Fuchsia WHEEL_DELTA, and (roughly) Firefox on
 // Linux.
 // static
@@ -882,7 +882,7 @@ void KeyEvent::InitializeNative() {
   if (synthesize_key_repeat_enabled_ && IsRepeated(GetLastKeyEvent()))
     SetFlags(flags() | EF_IS_REPEAT);
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   NormalizeFlags();
 #elif BUILDFLAG(IS_WIN)
   // Only Windows has native character events.
