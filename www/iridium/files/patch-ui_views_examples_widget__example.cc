--- ui/views/examples/widget_example.cc.orig	2020-02-03 21:53:14 UTC
+++ ui/views/examples/widget_example.cc
@@ -70,7 +70,7 @@ void WidgetExample::CreateExampleView(View* container)
   BuildButton(container, "Popup widget", POPUP);
   BuildButton(container, "Dialog widget", DIALOG);
   BuildButton(container, "Modal Dialog", MODAL_DIALOG);
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   // Windows does not support TYPE_CONTROL top-level widgets.
   BuildButton(container, "Child widget", CHILD);
 #endif
