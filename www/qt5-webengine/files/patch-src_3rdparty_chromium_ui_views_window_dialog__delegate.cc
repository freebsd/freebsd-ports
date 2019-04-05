--- src/3rdparty/chromium/ui/views/window/dialog_delegate.cc.orig	2018-11-13 18:25:11 UTC
+++ src/3rdparty/chromium/ui/views/window/dialog_delegate.cc
@@ -65,7 +65,7 @@ Widget::InitParams DialogDelegate::GetDialogWidgetInit
   params.bounds = bounds;
   DialogDelegate* dialog = delegate->AsDialogDelegate();
 
-#if defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#if (defined(OS_LINUX) || defined(OS_BSD)) && !defined(OS_CHROMEOS)
   // The new style doesn't support unparented dialogs on Linux desktop.
   if (dialog)
     dialog->supports_custom_frame_ &= parent != NULL;
