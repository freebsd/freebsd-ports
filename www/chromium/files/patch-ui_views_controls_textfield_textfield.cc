--- ui/views/controls/textfield/textfield.cc.orig	2017-07-25 21:05:19.000000000 +0200
+++ ui/views/controls/textfield/textfield.cc	2017-08-02 16:52:12.933845000 +0200
@@ -58,7 +58,7 @@
 #include "ui/base/win/osk_display_manager.h"
 #endif
 
-#if defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#if (defined(OS_LINUX) || defined(OS_BSD)) && !defined(OS_CHROMEOS)
 #include "base/strings/utf_string_conversions.h"
 #include "ui/base/ime/linux/text_edit_command_auralinux.h"
 #include "ui/base/ime/linux/text_edit_key_bindings_delegate_auralinux.h"
@@ -165,14 +165,14 @@
     case ui::VKEY_BACK:
       if (!control)
         return ui::TextEditCommand::DELETE_BACKWARD;
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
       // Only erase by line break on Linux and ChromeOS.
       if (shift)
         return ui::TextEditCommand::DELETE_TO_BEGINNING_OF_LINE;
 #endif
       return ui::TextEditCommand::DELETE_WORD_BACKWARD;
     case ui::VKEY_DELETE:
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
       // Only erase by line break on Linux and ChromeOS.
       if (shift && control)
         return ui::TextEditCommand::DELETE_TO_END_OF_LINE;
@@ -233,7 +233,7 @@
 // Control-modified key combination, but we cannot extend it to other platforms
 // as Control has different meanings and behaviors.
 // https://crrev.com/2580483002/#msg46
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   return flags & ui::EF_CONTROL_DOWN;
 #else
   return false;
@@ -619,7 +619,7 @@
     ShowImeIfNeeded();
   }
 
-#if defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#if (defined(OS_LINUX) || defined(OS_BSD)) && !defined(OS_CHROMEOS)
   if (!handled && !had_focus && event.IsOnlyMiddleMouseButton())
     RequestFocus();
 #endif
@@ -658,7 +658,7 @@
   if (!textfield)
     return handled;
 
-#if defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#if (defined(OS_LINUX) || defined(OS_BSD)) && !defined(OS_CHROMEOS)
   ui::TextEditKeyBindingsDelegateAuraLinux* delegate =
       ui::GetTextEditKeyBindingsDelegate();
   std::vector<ui::TextEditCommandAuraLinux> commands;
@@ -801,7 +801,7 @@
 }
 
 bool Textfield::SkipDefaultKeyEventProcessing(const ui::KeyEvent& event) {
-#if defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#if (defined(OS_LINUX) || defined(OS_BSD)) && !defined(OS_CHROMEOS)
   // Skip any accelerator handling that conflicts with custom keybindings.
   ui::TextEditKeyBindingsDelegateAuraLinux* delegate =
       ui::GetTextEditKeyBindingsDelegate();
@@ -1897,7 +1897,7 @@
 }
 
 void Textfield::UpdateSelectionClipboard() {
-#if defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#if (defined(OS_LINUX) || defined(OS_BSD)) && !defined(OS_CHROMEOS)
   if (text_input_type_ != ui::TEXT_INPUT_TYPE_PASSWORD) {
     ui::ScopedClipboardWriter(ui::CLIPBOARD_TYPE_SELECTION)
         .WriteText(GetSelectedText());
