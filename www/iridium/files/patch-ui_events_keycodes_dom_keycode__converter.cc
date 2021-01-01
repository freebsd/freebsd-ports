--- ui/events/keycodes/dom/keycode_converter.cc.orig	2020-03-16 18:40:15 UTC
+++ ui/events/keycodes/dom/keycode_converter.cc
@@ -20,7 +20,7 @@ namespace {
 #if defined(OS_WIN)
 #define DOM_CODE(usb, evdev, xkb, win, mac, code, id) \
   { usb, win, code }
-#elif defined(OS_LINUX)
+#elif defined(OS_LINUX) || defined(OS_BSD)
 #define DOM_CODE(usb, evdev, xkb, win, mac, code, id) \
   { usb, xkb, code }
 #elif defined(OS_MACOSX)
