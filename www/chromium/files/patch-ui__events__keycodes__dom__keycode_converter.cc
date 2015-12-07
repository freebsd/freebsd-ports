--- ui/events/keycodes/dom/keycode_converter.cc.orig	2015-10-14 03:01:24.000000000 -0400
+++ ui/events/keycodes/dom/keycode_converter.cc	2015-10-23 14:17:55.716373000 -0400
@@ -17,7 +17,7 @@
 // and DOM Level 3 |code| strings.
 #if defined(OS_WIN)
 #define USB_KEYMAP(usb, evdev, xkb, win, mac, code, id) {usb, win, code}
-#elif defined(OS_LINUX)
+#elif defined(OS_LINUX) || defined(OS_BSD)
 #define USB_KEYMAP(usb, evdev, xkb, win, mac, code, id) {usb, xkb, code}
 #elif defined(OS_MACOSX)
 #define USB_KEYMAP(usb, evdev, xkb, win, mac, code, id) {usb, mac, code}
