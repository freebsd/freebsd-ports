--- src/3rdparty/chromium/ui/events/keycodes/dom/keycode_converter.cc.orig	2017-01-26 00:49:31 UTC
+++ src/3rdparty/chromium/ui/events/keycodes/dom/keycode_converter.cc
@@ -19,7 +19,7 @@ namespace {
 // and DOM Level 3 |code| strings.
 #if defined(OS_WIN)
 #define USB_KEYMAP(usb, evdev, xkb, win, mac, code, id) {usb, win, code}
-#elif defined(OS_LINUX)
+#elif defined(OS_LINUX) || defined(OS_BSD)
 #define USB_KEYMAP(usb, evdev, xkb, win, mac, code, id) {usb, xkb, code}
 #elif defined(OS_MACOSX)
 #define USB_KEYMAP(usb, evdev, xkb, win, mac, code, id) {usb, mac, code}
