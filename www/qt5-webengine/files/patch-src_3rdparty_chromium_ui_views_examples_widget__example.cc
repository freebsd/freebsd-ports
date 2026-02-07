--- src/3rdparty/chromium/ui/views/examples/widget_example.cc.orig	2021-12-15 16:12:54 UTC
+++ src/3rdparty/chromium/ui/views/examples/widget_example.cc
@@ -67,7 +67,7 @@ void WidgetExample::CreateExampleView(View* container)
               DIALOG);
   BuildButton(container, GetStringUTF16(IDS_WIDGET_MODAL_BUTTON_LABEL),
               MODAL_DIALOG);
-#if defined(OS_LINUX) || defined(OS_CHROMEOS)
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
   // Windows does not support TYPE_CONTROL top-level widgets.
   BuildButton(container, GetStringUTF16(IDS_WIDGET_CHILD_WIDGET_BUTTON_LABEL),
               CHILD);
