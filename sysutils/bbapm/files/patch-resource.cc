--- resource.cc.orig	Fri Dec  7 19:42:46 2001
+++ resource.cc	Fri Dec  7 19:42:57 2001
@@ -28,6 +28,9 @@
 Resource::Resource(ToolWindow * toolwindow):
 BaseResource(toolwindow)
 {
+    frame.font = NULL;
+    label.font = NULL;
+
     Load();
 } 
