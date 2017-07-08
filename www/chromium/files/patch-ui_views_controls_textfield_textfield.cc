--- ui/views/controls/textfield/textfield.cc.orig	2017-06-05 19:03:30 UTC
+++ ui/views/controls/textfield/textfield.cc
@@ -54,7 +54,7 @@
 #include "ui/base/win/osk_display_manager.h"
 #endif
 
-#if defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#if (defined(OS_LINUX) || defined(OS_BSD)) && !defined(OS_CHROMEOS)
 #include "base/strings/utf_string_conversions.h"
 #include "ui/base/ime/linux/text_edit_command_auralinux.h"
 #include "ui/base/ime/linux/text_edit_key_bindings_delegate_auralinux.h"
@@ -153,14 +153,14 @@ ui::TextEditCommand GetCommandForKeyEvent(const ui::Ke
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
@@ -607,7 +607,7 @@ bool Textfield::OnMousePressed(const ui::MouseEvent& e
     ShowImeIfNeeded();
   }
 
-#if defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#if (defined(OS_LINUX) || defined(OS_BSD)) && !defined(OS_CHROMEOS)
   if (!handled && !had_focus && event.IsOnlyMiddleMouseButton())
     RequestFocus();
 #endif
@@ -646,7 +646,7 @@ bool Textfield::OnKeyPressed(const ui::KeyEvent& event
   if (!textfield)
     return handled;
 
-#if defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#if (defined(OS_LINUX) || defined(OS_BSD)) && !defined(OS_CHROMEOS)
   ui::TextEditKeyBindingsDelegateAuraLinux* delegate =
       ui::GetTextEditKeyBindingsDelegate();
   std::vector<ui::TextEditCommandAuraLinux> commands;
@@ -789,7 +789,7 @@ void Textfield::AboutToRequestFocusFromTabTraversal(bo
 }
 
 bool Textfield::SkipDefaultKeyEventProcessing(const ui::KeyEvent& event) {
-#if defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#if (defined(OS_LINUX) || defined(OS_BSD)) && !defined(OS_CHROMEOS)
   // Skip any accelerator handling that conflicts with custom keybindings.
   ui::TextEditKeyBindingsDelegateAuraLinux* delegate =
       ui::GetTextEditKeyBindingsDelegate();
@@ -1080,7 +1080,7 @@ void Textfield::WriteDragDataForView(View* sender,
 
   SkBitmap bitmap;
   float raster_scale = ScaleFactorForDragFromWidget(GetWidget());
-#if defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#if (defined(OS_LINUX) || defined(OS_BSD)) && !defined(OS_CHROMEOS)
   // Desktop Linux Aura does not yet support transparency in drag images.
   SkColor color = GetBackgroundColor();
 #else
@@ -1877,7 +1877,7 @@ bool Textfield::PasteSelectionClipboard() {
 }
 
 void Textfield::UpdateSelectionClipboard() {
-#if defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#if (defined(OS_LINUX) || defined(OS_BSD)) && !defined(OS_CHROMEOS)
   if (text_input_type_ != ui::TEXT_INPUT_TYPE_PASSWORD) {
     ui::ScopedClipboardWriter(ui::CLIPBOARD_TYPE_SELECTION)
         .WriteText(GetSelectedText());
