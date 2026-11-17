--- src/components/autofill/content/renderer/at_memory_handler.cc.orig	2026-10-18 18:43:23 UTC
+++ src/components/autofill/content/renderer/at_memory_handler.cc
@@ -62,7 +62,7 @@ bool IsPrintable(const WebKeyboardEvent&
   if (base::IsAsciiControl(event.text[0]) || event.text[1] != 0) {
     return false;
   }
-  if constexpr (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN)) {
+  if constexpr (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)) {
     // On Linux and Windows, Alt+X is not printable.
     return !(event.GetModifiers() & blink::WebInputEvent::kAltKey);
   }
