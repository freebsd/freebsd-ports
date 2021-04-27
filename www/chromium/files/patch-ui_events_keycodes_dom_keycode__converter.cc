--- ui/events/keycodes/dom/keycode_converter.cc.orig	2021-04-20 18:58:56 UTC
+++ ui/events/keycodes/dom/keycode_converter.cc
@@ -24,7 +24,7 @@ namespace {
 #if defined(OS_WIN)
 #define DOM_CODE(usb, evdev, xkb, win, mac, code, id) \
   { usb, win, code }
-#elif defined(OS_LINUX) || defined(OS_CHROMEOS)
+#elif defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
 #define DOM_CODE(usb, evdev, xkb, win, mac, code, id) \
   { usb, xkb, code }
 #elif defined(OS_APPLE)
@@ -148,7 +148,7 @@ int KeycodeConverter::DomCodeToNativeKeycode(DomCode c
   return UsbKeycodeToNativeKeycode(static_cast<uint32_t>(code));
 }
 
-#if defined(OS_LINUX) || defined(OS_CHROMEOS)
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
 // static
 DomCode KeycodeConverter::XkbKeycodeToDomCode(uint32_t xkb_keycode) {
   // Currently XKB keycode is the native keycode.
@@ -163,6 +163,7 @@ uint32_t KeycodeConverter::DomCodeToXkbKeycode(DomCode
   return static_cast<uint32_t>(DomCodeToNativeKeycode(code));
 }
 
+#if !defined(OS_BSD)
 // static
 DomCode KeycodeConverter::EvdevCodeToDomCode(int evdev_code) {
   // Currently XKB keycode is the native keycode.
@@ -176,6 +177,7 @@ int KeycodeConverter::DomCodeToEvdevCode(DomCode code)
   // TODO(crbug.com/1135034): Replace with evdev.
   return XkbKeycodeToEvdevCode(DomCodeToXkbKeycode(code));
 }
+#endif
 #endif
 
 // static
