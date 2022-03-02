--- ui/events/keycodes/dom/keycode_converter.cc.orig	2022-02-28 16:54:41 UTC
+++ ui/events/keycodes/dom/keycode_converter.cc
@@ -24,7 +24,7 @@ namespace {
 #if BUILDFLAG(IS_WIN)
 #define DOM_CODE(usb, evdev, xkb, win, mac, code, id) \
   { usb, win, code }
-#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 #define DOM_CODE(usb, evdev, xkb, win, mac, code, id) \
   { usb, xkb, code }
 #elif BUILDFLAG(IS_APPLE)
