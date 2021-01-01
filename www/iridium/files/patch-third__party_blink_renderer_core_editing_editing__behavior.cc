--- third_party/blink/renderer/core/editing/editing_behavior.cc.orig	2020-03-16 18:39:56 UTC
+++ third_party/blink/renderer/core/editing/editing_behavior.cc
@@ -274,7 +274,7 @@ bool EditingBehavior::ShouldInsertCharacter(const Keyb
   // unexpected behaviour
   if (ch < ' ')
     return false;
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   // According to XKB map no keyboard combinations with ctrl key are mapped to
   // printable characters, however we need the filter as the DomKey/text could
   // contain printable characters.
