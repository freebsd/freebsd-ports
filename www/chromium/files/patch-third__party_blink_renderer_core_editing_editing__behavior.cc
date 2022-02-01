--- third_party/blink/renderer/core/editing/editing_behavior.cc.orig	2021-12-14 11:45:11 UTC
+++ third_party/blink/renderer/core/editing/editing_behavior.cc
@@ -280,7 +280,7 @@ bool EditingBehavior::ShouldInsertCharacter(const Keyb
   // unexpected behaviour
   if (ch < ' ')
     return false;
-#if defined(OS_LINUX) || defined(OS_CHROMEOS)
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
   // According to XKB map no keyboard combinations with ctrl key are mapped to
   // printable characters, however we need the filter as the DomKey/text could
   // contain printable characters.
