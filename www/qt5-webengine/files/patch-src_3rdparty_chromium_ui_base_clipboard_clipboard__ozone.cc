--- src/3rdparty/chromium/ui/base/clipboard/clipboard_ozone.cc.orig	2021-12-15 16:12:54 UTC
+++ src/3rdparty/chromium/ui/base/clipboard/clipboard_ozone.cc
@@ -308,7 +308,7 @@ class ClipboardOzone::AsyncClipboardOzone {
 };
 
 // Uses the factory in the clipboard_linux otherwise.
-#if defined(OS_CHROMEOS) || !defined(OS_LINUX)
+#if defined(OS_CHROMEOS) || (!defined(OS_LINUX) && !defined(OS_BSD))
 // Clipboard factory method.
 Clipboard* Clipboard::Create() {
 // linux-chromeos uses non-backed clipboard by default, but supports ozone x11
