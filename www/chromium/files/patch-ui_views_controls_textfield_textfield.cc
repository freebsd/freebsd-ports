--- ui/views/controls/textfield/textfield.cc.orig	2016-05-11 19:02:36 UTC
+++ ui/views/controls/textfield/textfield.cc
@@ -47,7 +47,7 @@
 #include "base/win/win_util.h"
 #endif
 
-#if defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#if (defined(OS_LINUX) || defined(OS_BSD)) && !defined(OS_CHROMEOS)
 #include "base/strings/utf_string_conversions.h"
 #include "ui/events/linux/text_edit_command_auralinux.h"
 #include "ui/events/linux/text_edit_key_bindings_delegate_auralinux.h"
@@ -130,7 +130,7 @@ int GetCommandForKeyEvent(const ui::KeyE
     case ui::VKEY_BACK:
       if (!control || has_selection)
         return IDS_DELETE_BACKWARD;
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
       // Only erase by line break on Linux and ChromeOS.
       if (shift)
         return IDS_DELETE_TO_BEGINNING_OF_LINE;
@@ -139,7 +139,7 @@ int GetCommandForKeyEvent(const ui::KeyE
     case ui::VKEY_DELETE:
       if (!control || has_selection)
         return (shift && has_selection) ? IDS_APP_CUT : IDS_DELETE_FORWARD;
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
       // Only erase by line break on Linux and ChromeOS.
       if (shift)
         return IDS_DELETE_TO_END_OF_LINE;
@@ -154,7 +154,7 @@ int GetCommandForKeyEvent(const ui::KeyE
   }
 }
 
-#if defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#if (defined(OS_LINUX) || defined(OS_BSD)) && !defined(OS_CHROMEOS)
 // Convert a custom text edit |command| to the equivalent views command ID.
 int GetViewsCommand(const ui::TextEditCommandAuraLinux& command, bool rtl) {
   const bool select = command.extend_selection();
@@ -642,7 +642,7 @@ bool Textfield::OnMousePressed(const ui:
       OnAfterUserAction();
     }
 
-#if defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#if (defined(OS_LINUX) || defined(OS_BSD)) && !defined(OS_CHROMEOS)
     if (event.IsOnlyMiddleMouseButton()) {
       if (GetRenderText()->IsPointInSelection(event.location())) {
         OnBeforeUserAction();
@@ -711,7 +711,7 @@ bool Textfield::OnKeyPressed(const ui::K
   if (!textfield)
     return handled;
 
-#if defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#if (defined(OS_LINUX) || defined(OS_BSD)) && !defined(OS_CHROMEOS)
   ui::TextEditKeyBindingsDelegateAuraLinux* delegate =
       ui::GetTextEditKeyBindingsDelegate();
   std::vector<ui::TextEditCommandAuraLinux> commands;
@@ -846,7 +846,7 @@ void Textfield::AboutToRequestFocusFromT
 }
 
 bool Textfield::SkipDefaultKeyEventProcessing(const ui::KeyEvent& event) {
-#if defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#if (defined(OS_LINUX) || defined(OS_BSD)) && !defined(OS_CHROMEOS)
   // Skip any accelerator handling that conflicts with custom keybindings.
   ui::TextEditKeyBindingsDelegateAuraLinux* delegate =
       ui::GetTextEditKeyBindingsDelegate();
@@ -1105,7 +1105,7 @@ void Textfield::WriteDragDataForView(Vie
   scoped_ptr<gfx::Canvas> canvas(
       GetCanvasForDragImage(GetWidget(), label.size()));
   label.SetEnabledColor(GetTextColor());
-#if defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#if (defined(OS_LINUX) || defined(OS_BSD)) && !defined(OS_CHROMEOS)
   // Desktop Linux Aura does not yet support transparency in drag images.
   canvas->DrawColor(GetBackgroundColor());
 #endif
@@ -1880,7 +1880,7 @@ void Textfield::CreateTouchSelectionCont
 }
 
 void Textfield::UpdateSelectionClipboard() const {
-#if defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#if (defined(OS_LINUX) || defined(OS_BSD)) && !defined(OS_CHROMEOS)
   if (performing_user_action_ && HasSelection()) {
     ui::ScopedClipboardWriter(
         ui::CLIPBOARD_TYPE_SELECTION).WriteText(GetSelectedText());
