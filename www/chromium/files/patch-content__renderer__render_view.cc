--- content/renderer/render_view.cc.orig	2011-08-30 11:58:21.000000000 +0300
+++ content/renderer/render_view.cc	2011-09-11 22:31:33.000000000 +0300
@@ -437,7 +437,7 @@
     file_chooser_completions_.pop_front();
   }
 
-#if defined(OS_MACOSX)
+#if defined(OS_MACOSX) || defined(OS_FREEBSD)
   // Destroy all fake plugin window handles on the browser side.
   while (!fake_plugin_window_handles_.empty()) {
     // Make sure no NULL plugin window handles were inserted into this list.
@@ -1522,7 +1522,7 @@
 }
 
 bool RenderView::isSmartInsertDeleteEnabled() {
-#if defined(OS_MACOSX)
+#if defined(OS_MACOSX) || defined(OS_FREEBSD)
   return true;
 #else
   return false;
@@ -4187,7 +4187,7 @@
   return true;
 }
 
-#if defined(OS_MACOSX)
+#if defined(OS_MACOSX) || defined(OS_FREEBSD)
 void RenderView::PluginFocusChanged(bool focused, int plugin_id) {
   IPC::Message* msg = new ViewHostMsg_PluginFocusChanged(routing_id(),
                                                          focused, plugin_id);
