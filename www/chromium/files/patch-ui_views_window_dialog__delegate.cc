--- ui/views/window/dialog_delegate.cc.orig	2017-06-05 19:03:30 UTC
+++ ui/views/window/dialog_delegate.cc
@@ -57,7 +57,7 @@ Widget::InitParams DialogDelegate::GetDialogWidgetInit
   params.bounds = bounds;
   DialogDelegate* dialog = delegate->AsDialogDelegate();
 
-#if defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#if (defined(OS_LINUX) || defined(OS_BSD)) && !defined(OS_CHROMEOS)
   // The new style doesn't support unparented dialogs on Linux desktop.
   if (dialog)
     dialog->supports_custom_frame_ &= parent != NULL;
