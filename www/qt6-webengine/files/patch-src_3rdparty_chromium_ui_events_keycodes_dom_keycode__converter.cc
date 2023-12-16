--- src/3rdparty/chromium/ui/events/keycodes/dom/keycode_converter.cc.orig	2022-07-22 17:30:31 UTC
+++ src/3rdparty/chromium/ui/events/keycodes/dom/keycode_converter.cc
@@ -11,7 +11,7 @@
 #include "ui/events/keycodes/dom/dom_code.h"
 #include "ui/events/keycodes/dom/dom_key.h"
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_FREEBSD)
 #include <linux/input.h>
 #endif
 
@@ -24,7 +24,7 @@ namespace {
 #if BUILDFLAG(IS_WIN)
 #define DOM_CODE(usb, evdev, xkb, win, mac, code, id) \
   { usb, win, code }
-#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 #define DOM_CODE(usb, evdev, xkb, win, mac, code, id) \
   { usb, xkb, code }
 #elif BUILDFLAG(IS_APPLE)
@@ -58,7 +58,7 @@ struct DomKeyMapEntry {
 #undef DOM_KEY_MAP
 #undef DOM_KEY_UNI
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_FREEBSD)
 
 // The offset between XKB Keycode and evdev code.
 constexpr int kXkbKeycodeOffset = 8;
@@ -139,7 +139,7 @@ int KeycodeConverter::DomCodeToNativeKeycode(DomCode c
   return UsbKeycodeToNativeKeycode(static_cast<uint32_t>(code));
 }
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_FREEBSD)
 // static
 DomCode KeycodeConverter::XkbKeycodeToDomCode(uint32_t xkb_keycode) {
   // Currently XKB keycode is the native keycode.
