--- src/third_party/blink/renderer/core/editing/editing_behavior.cc.orig	2026-10-18 18:43:23 UTC
+++ src/third_party/blink/renderer/core/editing/editing_behavior.cc
@@ -144,7 +144,7 @@ const KeyboardCodeKeyDownEntry kKeyboard
     {VKEY_DELETE, 0, "DeleteForward"},
     {VKEY_BACK, OPTION_OR_CTRL_KEY, "DeleteWordBackward"},
     {VKEY_DELETE, OPTION_OR_CTRL_KEY, "DeleteWordForward"},
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
     {VKEY_BACK, kCtrlKey | kShiftKey, "DeleteToBeginningOfLine"},
 #endif
 #if BUILDFLAG(IS_MAC)
@@ -313,7 +313,7 @@ bool EditingBehavior::ShouldInsertCharac
   // unexpected behaviour
   if (ch < ' ')
     return false;
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   // According to XKB map no keyboard combinations with ctrl key are mapped to
   // printable characters, however we need the filter as the DomKey/text could
   // contain printable characters.
