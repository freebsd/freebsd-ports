--- ui/views/window/dialog_delegate.cc.orig	2015-04-14 18:19:00.000000000 -0400
+++ ui/views/window/dialog_delegate.cc	2015-04-28 07:49:18.261990000 -0400
@@ -48,7 +48,7 @@
   params.bounds = bounds;
   DialogDelegate* dialog = delegate->AsDialogDelegate();
 
-#if defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#if (defined(OS_LINUX) || defined(OS_BSD)) && !defined(OS_CHROMEOS)
   // The new style doesn't support unparented dialogs on Linux desktop.
   if (dialog)
     dialog->supports_new_style_ &= parent != NULL;
