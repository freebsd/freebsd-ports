--- third_party/blink/renderer/core/editing/editing_behavior.cc.orig	2021-07-19 18:45:21 UTC
+++ third_party/blink/renderer/core/editing/editing_behavior.cc
@@ -273,7 +273,7 @@ bool EditingBehavior::ShouldInsertCharacter(const Keyb
   // unexpected behaviour
   if (ch < ' ')
     return false;
-#if defined(OS_LINUX) || defined(OS_CHROMEOS)
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
   // According to XKB map no keyboard combinations with ctrl key are mapped to
   // printable characters, however we need the filter as the DomKey/text could
   // contain printable characters.
