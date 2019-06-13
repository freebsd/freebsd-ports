--- ui/views/examples/widget_example.cc.orig	2019-06-04 18:55:50 UTC
+++ ui/views/examples/widget_example.cc
@@ -78,7 +78,7 @@ void WidgetExample::CreateExampleView(View* container)
   BuildButton(container, "Popup widget", POPUP);
   BuildButton(container, "Dialog widget", DIALOG);
   BuildButton(container, "Modal Dialog", MODAL_DIALOG);
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   // Windows does not support TYPE_CONTROL top-level widgets.
   BuildButton(container, "Child widget", CHILD);
 #endif
