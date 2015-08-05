--- ui/events/keycodes/dom/keycode_converter.cc.orig	2015-07-22 18:31:47.703757000 -0400
+++ ui/events/keycodes/dom/keycode_converter.cc	2015-07-22 18:32:17.605463000 -0400
@@ -16,7 +16,7 @@
 // and DOM Level 3 |code| strings.
 #if defined(OS_WIN)
 #define USB_KEYMAP(usb, xkb, win, mac, code, id) {usb, win, code}
-#elif defined(OS_LINUX)
+#elif defined(OS_LINUX) || defined(OS_BSD)
 #define USB_KEYMAP(usb, xkb, win, mac, code, id) {usb, xkb, code}
 #elif defined(OS_MACOSX)
 #define USB_KEYMAP(usb, xkb, win, mac, code, id) {usb, mac, code}
