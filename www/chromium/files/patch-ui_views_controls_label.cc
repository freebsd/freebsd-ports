--- ui/views/controls/label.cc.orig	2020-09-08 19:14:28 UTC
+++ ui/views/controls/label.cc
@@ -710,7 +710,7 @@ bool Label::OnMousePressed(const ui::MouseEvent& event
     GetFocusManager()->SetFocusedView(this);
   }
 
-#if defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#if (defined(OS_LINUX) || defined(OS_BSD)) && !defined(OS_CHROMEOS)
   if (event.IsOnlyMiddleMouseButton() && GetFocusManager() && !had_focus)
     GetFocusManager()->SetFocusedView(this);
 #endif
@@ -896,7 +896,7 @@ bool Label::PasteSelectionClipboard() {
 }
 
 void Label::UpdateSelectionClipboard() {
-#if defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#if (defined(OS_LINUX) && !defined(OS_CHROMEOS)) || defined(OS_BSD)
   if (!GetObscured()) {
     ui::ScopedClipboardWriter(ui::ClipboardBuffer::kSelection)
         .WriteText(GetSelectedText());
