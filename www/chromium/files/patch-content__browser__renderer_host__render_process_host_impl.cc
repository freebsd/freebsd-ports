--- content/browser/renderer_host/render_process_host_impl.cc.orig	2012-01-29 16:19:50.000000000 +0200
+++ content/browser/renderer_host/render_process_host_impl.cc	2012-01-29 16:20:14.000000000 +0200
@@ -806,7 +806,7 @@
                   STANDARD_RIGHTS_REQUIRED | FILE_MAP_READ | FILE_MAP_WRITE,
                   FALSE, 0);
   return TransportDIB::Map(section);
-#elif defined(OS_MACOSX)
+#elif defined(OS_MACOSX) || defined(OS_FREEBSD)
   // On OSX, the browser allocates all DIBs and keeps a file descriptor around
   // for each.
   return widget_helper_->MapTransportDIB(dib_id);
