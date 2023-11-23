--- third_party/blink/renderer/core/editing/editing_behavior.cc.orig	2023-11-22 14:00:11 UTC
+++ third_party/blink/renderer/core/editing/editing_behavior.cc
@@ -279,7 +279,7 @@ bool EditingBehavior::ShouldInsertCharacter(const Keyb
   // unexpected behaviour
   if (ch < ' ')
     return false;
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   // According to XKB map no keyboard combinations with ctrl key are mapped to
   // printable characters, however we need the filter as the DomKey/text could
   // contain printable characters.
