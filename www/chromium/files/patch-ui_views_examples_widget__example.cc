--- ui/views/examples/widget_example.cc.orig	2020-11-13 06:37:06 UTC
+++ ui/views/examples/widget_example.cc
@@ -67,7 +67,7 @@ void WidgetExample::CreateExampleView(View* container)
               DIALOG);
   BuildButton(container, GetStringUTF16(IDS_WIDGET_MODAL_BUTTON_LABEL),
               MODAL_DIALOG);
-#if defined(OS_LINUX) || defined(OS_CHROMEOS)
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
   // Windows does not support TYPE_CONTROL top-level widgets.
   BuildButton(container, GetStringUTF16(IDS_WIDGET_CHILD_WIDGET_BUTTON_LABEL),
               CHILD);
