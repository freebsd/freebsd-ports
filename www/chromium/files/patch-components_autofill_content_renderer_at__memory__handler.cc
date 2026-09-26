--- components/autofill/content/renderer/at_memory_handler.cc.orig	2026-09-25 15:26:43 UTC
+++ components/autofill/content/renderer/at_memory_handler.cc
@@ -65,7 +65,7 @@ bool IsPrintable(const WebKeyboardEvent& event) {
   if (base::IsAsciiControl(event.text[0]) || event.text[1] != 0) {
     return false;
   }
-  if constexpr (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN)) {
+  if constexpr (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)) {
     // On Linux and Windows, Alt+X is not printable.
     return !(event.GetModifiers() & blink::WebInputEvent::kAltKey);
   }
