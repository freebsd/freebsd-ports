--- ui/views/controls/textfield/textfield.cc.orig	2021-12-31 00:58:32 UTC
+++ ui/views/controls/textfield/textfield.cc
@@ -73,7 +73,7 @@
 
 // TODO(crbug.com/1052397): Revisit the macro expression once build flag switch
 // of lacros-chrome is complete.
-#if defined(OS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS)
+#if defined(OS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS) || defined(OS_BSD)
 #include "ui/base/ime/linux/text_edit_command_auralinux.h"
 #include "ui/base/ime/linux/text_edit_key_bindings_delegate_auralinux.h"
 #endif
@@ -166,7 +166,7 @@ bool IsControlKeyModifier(int flags) {
 // Control-modified key combination, but we cannot extend it to other platforms
 // as Control has different meanings and behaviors.
 // https://crrev.com/2580483002/#msg46
-#if defined(OS_LINUX) || defined(OS_CHROMEOS)
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
   return flags & ui::EF_CONTROL_DOWN;
 #else
   return false;
@@ -713,7 +713,7 @@ bool Textfield::OnKeyPressed(const ui::KeyEvent& event
 
 // TODO(crbug.com/1052397): Revisit the macro expression once build flag switch
 // of lacros-chrome is complete.
-#if defined(OS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS)
+#if defined(OS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS) || defined(OS_BSD)
   ui::TextEditKeyBindingsDelegateAuraLinux* delegate =
       ui::GetTextEditKeyBindingsDelegate();
   std::vector<ui::TextEditCommandAuraLinux> commands;
@@ -859,7 +859,7 @@ void Textfield::AboutToRequestFocusFromTabTraversal(bo
 bool Textfield::SkipDefaultKeyEventProcessing(const ui::KeyEvent& event) {
 // TODO(crbug.com/1052397): Revisit the macro expression once build flag switch
 // of lacros-chrome is complete.
-#if defined(OS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS)
+#if defined(OS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS) || defined(OS_BSD)
   // Skip any accelerator handling that conflicts with custom keybindings.
   ui::TextEditKeyBindingsDelegateAuraLinux* delegate =
       ui::GetTextEditKeyBindingsDelegate();
@@ -1722,7 +1722,7 @@ bool Textfield::ShouldDoLearning() {
   return false;
 }
 
-#if defined(OS_WIN) || defined(OS_LINUX) || defined(OS_CHROMEOS)
+#if defined(OS_WIN) || defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
 // TODO(https://crbug.com/952355): Implement this method to support Korean IME
 // reconversion feature on native text fields (e.g. find bar).
 bool Textfield::SetCompositionFromExistingText(
@@ -2222,14 +2222,14 @@ ui::TextEditCommand Textfield::GetCommandForKeyEvent(
 #endif
         return ui::TextEditCommand::DELETE_BACKWARD;
       }
-#if defined(OS_LINUX) || defined(OS_CHROMEOS)
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
       // Only erase by line break on Linux and ChromeOS.
       if (shift)
         return ui::TextEditCommand::DELETE_TO_BEGINNING_OF_LINE;
 #endif
       return ui::TextEditCommand::DELETE_WORD_BACKWARD;
     case ui::VKEY_DELETE:
-#if defined(OS_LINUX) || defined(OS_CHROMEOS)
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
       // Only erase by line break on Linux and ChromeOS.
       if (shift && control)
         return ui::TextEditCommand::DELETE_TO_END_OF_LINE;
