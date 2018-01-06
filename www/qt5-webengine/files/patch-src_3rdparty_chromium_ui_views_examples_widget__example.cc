--- src/3rdparty/chromium/ui/views/examples/widget_example.cc.orig	2017-01-26 00:49:32 UTC
+++ src/3rdparty/chromium/ui/views/examples/widget_example.cc
@@ -77,7 +77,7 @@ void WidgetExample::CreateExampleView(Vi
   BuildButton(container, "Popup widget", POPUP);
   BuildButton(container, "Dialog widget", DIALOG);
   BuildButton(container, "Modal Dialog", MODAL_DIALOG);
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   // Windows does not support TYPE_CONTROL top-level widgets.
   BuildButton(container, "Child widget", CHILD);
 #endif
