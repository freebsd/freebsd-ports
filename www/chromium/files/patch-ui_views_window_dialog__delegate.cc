--- ui/views/window/dialog_delegate.cc.orig	2017-04-19 19:06:55 UTC
+++ ui/views/window/dialog_delegate.cc
@@ -57,7 +57,7 @@ Widget::InitParams DialogDelegate::GetDi
   params.bounds = bounds;
   DialogDelegate* dialog = delegate->AsDialogDelegate();
 
-#if defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#if (defined(OS_LINUX) || defined(OS_BSD)) && !defined(OS_CHROMEOS)
   // The new style doesn't support unparented dialogs on Linux desktop.
   if (dialog)
     dialog->supports_custom_frame_ &= parent != NULL;
