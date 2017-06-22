--- ui/views/controls/label.cc.orig	2017-06-05 19:03:30 UTC
+++ ui/views/controls/label.cc
@@ -553,7 +553,7 @@ bool Label::OnMousePressed(const ui::MouseEvent& event
     GetFocusManager()->SetFocusedView(this);
   }
 
-#if defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#if (defined(OS_LINUX) || defined(OS_BSD)) && !defined(OS_CHROMEOS)
   if (event.IsOnlyMiddleMouseButton() && GetFocusManager() && !had_focus)
     GetFocusManager()->SetFocusedView(this);
 #endif
@@ -729,7 +729,7 @@ bool Label::PasteSelectionClipboard() {
 }
 
 void Label::UpdateSelectionClipboard() {
-#if defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#if (defined(OS_LINUX) || defined(OS_BSD)) && !defined(OS_CHROMEOS)
   if (!obscured()) {
     ui::ScopedClipboardWriter(ui::CLIPBOARD_TYPE_SELECTION)
         .WriteText(GetSelectedText());
