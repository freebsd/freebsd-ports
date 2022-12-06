--- ui/events/event.cc.orig	2022-12-06 08:09:13 UTC
+++ ui/events/event.cc
@@ -419,7 +419,7 @@ std::string LocatedEvent::ToString() const {
 MouseEvent::MouseEvent(const PlatformEvent& native_event)
     : LocatedEvent(native_event),
       changed_button_flags_(GetChangedMouseButtonFlagsFromNative(native_event)),
-#if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
       movement_(GetMouseMovementFromNative(native_event)),
 #endif
       pointer_details_(GetMousePointerDetailsFromNative(native_event)) {
@@ -918,7 +918,7 @@ void KeyEvent::InitializeNative() {
   if (synthesize_key_repeat_enabled_ && IsRepeated(GetLastKeyEvent()))
     set_flags(flags() | EF_IS_REPEAT);
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   NormalizeFlags();
 #elif BUILDFLAG(IS_WIN)
   // Only Windows has native character events.
