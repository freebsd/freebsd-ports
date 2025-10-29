--- third_party/blink/renderer/core/editing/editing_behavior.cc.orig	2025-10-28 14:29:43 UTC
+++ third_party/blink/renderer/core/editing/editing_behavior.cc
@@ -138,7 +138,7 @@ const KeyboardCodeKeyDownEntry kKeyboardCodeKeyDownEnt
     {VKEY_DELETE, 0, "DeleteForward"},
     {VKEY_BACK, OPTION_OR_CTRL_KEY, "DeleteWordBackward"},
     {VKEY_DELETE, OPTION_OR_CTRL_KEY, "DeleteWordForward"},
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
     {VKEY_BACK, kCtrlKey | kShiftKey, "DeleteToBeginningOfLine"},
 #endif
 #if BUILDFLAG(IS_MAC)
@@ -307,7 +307,7 @@ bool EditingBehavior::ShouldInsertCharacter(const Keyb
   // unexpected behaviour
   if (ch < ' ')
     return false;
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   // According to XKB map no keyboard combinations with ctrl key are mapped to
   // printable characters, however we need the filter as the DomKey/text could
   // contain printable characters.
