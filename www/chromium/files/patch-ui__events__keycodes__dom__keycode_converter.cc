--- ui/events/keycodes/dom/keycode_converter.cc.orig	2015-12-05 19:58:49.948228000 +0100
+++ ui/events/keycodes/dom/keycode_converter.cc	2015-12-05 19:59:00.416726000 +0100
@@ -17,7 +17,7 @@
 // and DOM Level 3 |code| strings.
 #if defined(OS_WIN)
 #define USB_KEYMAP(usb, evdev, xkb, win, mac, code, id) {usb, win, code}
-#elif defined(OS_LINUX)
+#elif defined(OS_LINUX) || defined(OS_BSD)
 #define USB_KEYMAP(usb, evdev, xkb, win, mac, code, id) {usb, xkb, code}
 #elif defined(OS_MACOSX)
 #define USB_KEYMAP(usb, evdev, xkb, win, mac, code, id) {usb, mac, code}
