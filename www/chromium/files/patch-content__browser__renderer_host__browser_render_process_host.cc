--- content/browser/renderer_host/browser_render_process_host.cc.orig	2011-03-20 22:02:04.283738713 +0200
+++ content/browser/renderer_host/browser_render_process_host.cc	2011-03-20 22:02:04.448747953 +0200
@@ -886,7 +886,7 @@
   HANDLE section = app::win::GetSectionFromProcess(
       dib_id.handle, GetHandle(), false /* read write */);
   return TransportDIB::Map(section);
-#elif defined(OS_MACOSX)
+#elif defined(OS_MACOSX) || defined(OS_FREEBSD)
   // On OSX, the browser allocates all DIBs and keeps a file descriptor around
   // for each.
   return widget_helper_->MapTransportDIB(dib_id);
