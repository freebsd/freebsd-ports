--- content/renderer/render_view_impl.cc.orig	2011-11-01 10:42:35.000000000 +0200
+++ content/renderer/render_view_impl.cc	2011-11-21 22:20:15.000000000 +0200
@@ -423,7 +423,7 @@
     file_chooser_completions_.pop_front();
   }
 
-#if defined(OS_MACOSX)
+#if defined(OS_MACOSX) || defined(OS_FREEBSD)
   // Destroy all fake plugin window handles on the browser side.
   while (!fake_plugin_window_handles_.empty()) {
     // Make sure no NULL plugin window handles were inserted into this list.
@@ -1499,7 +1499,7 @@
 }
 
 bool RenderViewImpl::isSmartInsertDeleteEnabled() {
-#if defined(OS_MACOSX)
+#if defined(OS_MACOSX) || defined(OS_FREEBSD)
   return true;
 #else
   return false;
@@ -4318,7 +4318,7 @@
 }
 #endif
 
-#if defined(OS_MACOSX)
+#if defined(OS_MACOSX) || defined(OS_FREEBSD)
 void RenderViewImpl::PluginFocusChanged(bool focused, int plugin_id) {
   IPC::Message* msg = new ViewHostMsg_PluginFocusChanged(routing_id(),
                                                          focused, plugin_id);
