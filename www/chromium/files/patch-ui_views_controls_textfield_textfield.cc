--- ui/views/controls/textfield/textfield.cc.orig	2016-08-04 09:54:43.724487000 -0400
+++ ui/views/controls/textfield/textfield.cc	2016-08-04 09:57:23.923660000 -0400
@@ -48,7 +48,7 @@
 #include "base/win/win_util.h"
 #endif
 
-#if defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#if (defined(OS_LINUX) || defined(OS_BSD)) && !defined(OS_CHROMEOS)
 #include "base/strings/utf_string_conversions.h"
 #include "ui/events/linux/text_edit_command_auralinux.h"
 #include "ui/events/linux/text_edit_key_bindings_delegate_auralinux.h"
@@ -131,14 +131,14 @@
     case ui::VKEY_BACK:
       if (!control)
         return IDS_DELETE_BACKWARD;
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
       // Only erase by line break on Linux and ChromeOS.
       if (shift)
         return IDS_DELETE_TO_BEGINNING_OF_LINE;
 #endif
       return IDS_DELETE_WORD_BACKWARD;
     case ui::VKEY_DELETE:
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
       // Only erase by line break on Linux and ChromeOS.
       if (shift && control)
         return IDS_DELETE_TO_END_OF_LINE;
@@ -155,7 +155,7 @@
   }
 }
 
-#if defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#if (defined(OS_LINUX) || defined(OS_BSD)) && !defined(OS_CHROMEOS)
 // Convert a custom text edit |command| to the equivalent views command ID.
 int GetViewsCommand(const ui::TextEditCommandAuraLinux& command, bool rtl) {
   const bool select = command.extend_selection();
@@ -643,7 +643,7 @@
       OnAfterUserAction();
     }
 
-#if defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#if (defined(OS_LINUX) || defined(OS_BSD)) && !defined(OS_CHROMEOS)
     if (event.IsOnlyMiddleMouseButton()) {
       if (GetRenderText()->IsPointInSelection(event.location())) {
         OnBeforeUserAction();
@@ -712,7 +712,7 @@
   if (!textfield)
     return handled;
 
-#if defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#if (defined(OS_LINUX) || defined(OS_BSD)) && !defined(OS_CHROMEOS)
   ui::TextEditKeyBindingsDelegateAuraLinux* delegate =
       ui::GetTextEditKeyBindingsDelegate();
   std::vector<ui::TextEditCommandAuraLinux> commands;
@@ -847,7 +847,7 @@
 }
 
 bool Textfield::SkipDefaultKeyEventProcessing(const ui::KeyEvent& event) {
-#if defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#if (defined(OS_LINUX) || defined(OS_BSD)) && !defined(OS_CHROMEOS)
   // Skip any accelerator handling that conflicts with custom keybindings.
   ui::TextEditKeyBindingsDelegateAuraLinux* delegate =
       ui::GetTextEditKeyBindingsDelegate();
@@ -1106,7 +1106,7 @@
   std::unique_ptr<gfx::Canvas> canvas(
       GetCanvasForDragImage(GetWidget(), label.size()));
   label.SetEnabledColor(GetTextColor());
-#if defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#if (defined(OS_LINUX) || defined(OS_BSD)) && !defined(OS_CHROMEOS)
   // Desktop Linux Aura does not yet support transparency in drag images.
   canvas->DrawColor(GetBackgroundColor());
 #endif
@@ -1908,7 +1908,7 @@
 }
 
 void Textfield::UpdateSelectionClipboard() const {
-#if defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#if (defined(OS_LINUX) || defined(OS_BSD)) && !defined(OS_CHROMEOS)
   if (performing_user_action_ && HasSelection()) {
     ui::ScopedClipboardWriter(
         ui::CLIPBOARD_TYPE_SELECTION).WriteText(GetSelectedText());
