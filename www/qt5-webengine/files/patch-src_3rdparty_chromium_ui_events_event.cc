--- src/3rdparty/chromium/ui/events/event.cc.orig	2021-12-15 16:12:54 UTC
+++ src/3rdparty/chromium/ui/events/event.cc
@@ -469,7 +469,7 @@ MouseEvent::MouseEvent(const PlatformEvent& native_eve
 MouseEvent::MouseEvent(const PlatformEvent& native_event)
     : LocatedEvent(native_event),
       changed_button_flags_(GetChangedMouseButtonFlagsFromNative(native_event)),
-#if defined(OS_CHROMEOS) || defined(OS_LINUX)
+#if defined(OS_CHROMEOS) || defined(OS_LINUX) || defined(OS_BSD)
       movement_(GetMouseMovementFromNative(native_event)),
 #endif
       pointer_details_(GetMousePointerDetailsFromNative(native_event)) {
