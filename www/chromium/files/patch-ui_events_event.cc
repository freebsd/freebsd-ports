--- ui/events/event.cc.orig	2021-12-31 00:58:32 UTC
+++ ui/events/event.cc
@@ -452,7 +452,7 @@ std::string LocatedEvent::ToString() const {
 MouseEvent::MouseEvent(const PlatformEvent& native_event)
     : LocatedEvent(native_event),
       changed_button_flags_(GetChangedMouseButtonFlagsFromNative(native_event)),
-#if defined(OS_CHROMEOS) || defined(OS_LINUX)
+#if defined(OS_CHROMEOS) || defined(OS_LINUX) || defined(OS_BSD)
       movement_(GetMouseMovementFromNative(native_event)),
 #endif
       pointer_details_(GetMousePointerDetailsFromNative(native_event)) {
@@ -934,7 +934,7 @@ void KeyEvent::InitializeNative() {
   if (synthesize_key_repeat_enabled_ && IsRepeated(GetLastKeyEvent()))
     set_flags(flags() | EF_IS_REPEAT);
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   NormalizeFlags();
 #elif defined(OS_WIN)
   // Only Windows has native character events.
