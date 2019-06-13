--- ui/views/window/dialog_delegate.cc.orig	2019-06-04 18:55:50 UTC
+++ ui/views/window/dialog_delegate.cc
@@ -61,7 +61,7 @@ Widget::InitParams DialogDelegate::GetDialogWidgetInit
   params.bounds = bounds;
   DialogDelegate* dialog = delegate->AsDialogDelegate();
 
-#if defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#if (defined(OS_LINUX) || defined(OS_BSD)) && !defined(OS_CHROMEOS)
   // The new style doesn't support unparented dialogs on Linux desktop.
   if (dialog)
     dialog->supports_custom_frame_ &= parent != nullptr;
