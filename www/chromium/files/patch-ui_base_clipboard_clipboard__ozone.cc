--- ui/base/clipboard/clipboard_ozone.cc.orig	2021-04-14 18:41:37 UTC
+++ ui/base/clipboard/clipboard_ozone.cc
@@ -301,7 +301,7 @@ class ClipboardOzone::AsyncClipboardOzone {
 // of lacros-chrome is complete.
 // TODO(crbug.com/1052397): Revisit the macro expression once build flag switch
 // of lacros-chrome is complete.
-#if !(defined(OS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS))
+#if !(defined(OS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS) || defined(OS_BSD))
 // Clipboard factory method.
 Clipboard* Clipboard::Create() {
 // linux-chromeos uses non-backed clipboard by default, but supports ozone x11
