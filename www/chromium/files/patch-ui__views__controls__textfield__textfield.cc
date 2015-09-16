--- ui/views/controls/textfield/textfield.cc.orig	2015-04-14 18:31:23.000000000 -0400
+++ ui/views/controls/textfield/textfield.cc	2015-04-28 07:58:48.300682000 -0400
@@ -41,7 +41,7 @@
 #include "base/win/win_util.h"
 #endif
 
-#if defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#if (defined(OS_LINUX) || defined(OS_BSD)) && !defined(OS_CHROMEOS)
 #include "base/strings/utf_string_conversions.h"
 #include "ui/events/linux/text_edit_command_auralinux.h"
 #include "ui/events/linux/text_edit_key_bindings_delegate_auralinux.h"
@@ -124,7 +124,7 @@
     case ui::VKEY_BACK:
       if (!control || has_selection)
         return IDS_DELETE_BACKWARD;
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
       // Only erase by line break on Linux and ChromeOS.
       if (shift)
         return IDS_DELETE_TO_BEGINNING_OF_LINE;
@@ -133,7 +133,7 @@
     case ui::VKEY_DELETE:
       if (!control || has_selection)
         return (shift && has_selection) ? IDS_APP_CUT : IDS_DELETE_FORWARD;
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
       // Only erase by line break on Linux and ChromeOS.
       if (shift)
         return IDS_DELETE_TO_END_OF_LINE;
@@ -148,7 +148,7 @@
   }
 }
 
-#if defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#if (defined(OS_LINUX) || defined(OS_BSD)) && !defined(OS_CHROMEOS)
 // Convert a custom text edit |command| to the equivalent views command ID.
 int GetViewsCommand(const ui::TextEditCommandAuraLinux& command, bool rtl) {
   const bool select = command.extend_selection();
@@ -612,7 +612,7 @@
       OnAfterUserAction();
     }
 
-#if defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#if (defined(OS_LINUX) || defined(OS_BSD)) && !defined(OS_CHROMEOS)
     if (event.IsOnlyMiddleMouseButton()) {
       if (GetRenderText()->IsPointInSelection(event.location())) {
         OnBeforeUserAction();
@@ -678,7 +678,7 @@
   if (!textfield)
     return handled;
 
-#if defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#if (defined(OS_LINUX) || defined(OS_BSD)) && !defined(OS_CHROMEOS)
   ui::TextEditKeyBindingsDelegateAuraLinux* delegate =
       ui::GetTextEditKeyBindingsDelegate();
   std::vector<ui::TextEditCommandAuraLinux> commands;
@@ -805,7 +805,7 @@
 }
 
 bool Textfield::SkipDefaultKeyEventProcessing(const ui::KeyEvent& event) {
-#if defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#if (defined(OS_LINUX) || defined(OS_BSD)) && !defined(OS_CHROMEOS)
   // Skip any accelerator handling that conflicts with custom keybindings.
   ui::TextEditKeyBindingsDelegateAuraLinux* delegate =
       ui::GetTextEditKeyBindingsDelegate();
@@ -1061,7 +1061,7 @@
   scoped_ptr<gfx::Canvas> canvas(
       GetCanvasForDragImage(GetWidget(), label.size()));
   label.SetEnabledColor(GetTextColor());
-#if defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#if (defined(OS_LINUX) || defined(OS_BSD)) && !defined(OS_CHROMEOS)
   // Desktop Linux Aura does not yet support transparency in drag images.
   canvas->DrawColor(GetBackgroundColor());
 #endif
@@ -1855,7 +1855,7 @@
 }
 
 void Textfield::UpdateSelectionClipboard() const {
-#if defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#if (defined(OS_LINUX) || defined(OS_BSD)) && !defined(OS_CHROMEOS)
   if (performing_user_action_ && HasSelection()) {
     ui::ScopedClipboardWriter(
         ui::CLIPBOARD_TYPE_SELECTION).WriteText(GetSelectedText());
