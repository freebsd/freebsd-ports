--- ui/views/window/dialog_delegate.cc.orig	2016-05-11 19:02:36 UTC
+++ ui/views/window/dialog_delegate.cc
@@ -53,7 +53,7 @@ Widget* DialogDelegate::CreateDialogWidg
   params.bounds = bounds;
   DialogDelegate* dialog = delegate->AsDialogDelegate();
 
-#if defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#if (defined(OS_LINUX) || defined(OS_BSD)) && !defined(OS_CHROMEOS)
   // The new style doesn't support unparented dialogs on Linux desktop.
   if (dialog)
     dialog->supports_new_style_ &= parent != NULL;
