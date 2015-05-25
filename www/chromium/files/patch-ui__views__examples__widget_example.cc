--- ui/views/examples/widget_example.cc.orig	2015-05-13 18:23:12.000000000 -0400
+++ ui/views/examples/widget_example.cc	2015-05-20 17:45:57.913297000 -0400
@@ -82,7 +82,7 @@
   BuildButton(container, "Popup widget", POPUP);
   BuildButton(container, "Dialog widget", DIALOG);
   BuildButton(container, "Modal Dialog", MODAL_DIALOG);
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   // Windows does not support TYPE_CONTROL top-level widgets.
   BuildButton(container, "Child widget", CHILD);
 #endif

