--- ui/events/keycodes/dom/keycode_converter.h.orig	2021-04-22 08:32:20 UTC
+++ ui/events/keycodes/dom/keycode_converter.h
@@ -59,18 +59,20 @@ class KeycodeConverter {
   // Convert a DomCode into a native keycode.
   static int DomCodeToNativeKeycode(DomCode code);
 
-#if defined(OS_LINUX) || defined(OS_CHROMEOS)
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
   // Convert a XKB keycode into a DomCode.
   static DomCode XkbKeycodeToDomCode(uint32_t xkb_keycode);
 
   // Convert a DomCode into a XKB keycode.
   static uint32_t DomCodeToXkbKeycode(DomCode code);
 
+#if !defined(OS_BSD)
   // Convert an evdev code into DomCode.
   static DomCode EvdevCodeToDomCode(int evdev_code);
 
   // Convert a DomCode into an evdev code.
   static int DomCodeToEvdevCode(DomCode code);
+#endif
 #endif
 
   // Convert a UI Events |code| string value into a DomCode.
