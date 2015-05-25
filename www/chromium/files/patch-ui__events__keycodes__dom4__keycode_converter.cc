--- ui/events/keycodes/dom4/keycode_converter.cc.orig	2015-04-14 18:19:00.000000000 -0400
+++ ui/events/keycodes/dom4/keycode_converter.cc	2015-04-28 08:47:25.161132000 -0400
@@ -15,7 +15,7 @@
 // and DOM Level 3 |code| strings.
 #if defined(OS_WIN)
 #define USB_KEYMAP(usb, xkb, win, mac, code, id) {usb, win, code}
-#elif defined(OS_LINUX)
+#elif defined(OS_LINUX) || defined(OS_BSD)
 #define USB_KEYMAP(usb, xkb, win, mac, code, id) {usb, xkb, code}
 #elif defined(OS_MACOSX)
 #define USB_KEYMAP(usb, xkb, win, mac, code, id) {usb, mac, code}
