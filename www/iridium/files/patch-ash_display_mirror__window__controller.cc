--- ash/display/mirror_window_controller.cc.orig	2025-09-11 13:19:19 UTC
+++ ash/display/mirror_window_controller.cc
@@ -283,7 +283,11 @@ void MirrorWindowController::UpdateWindow(
       if (!base::Contains(display_info_list, iter->first,
                           &display::ManagedDisplayInfo::id)) {
         CloseAndDeleteHost(iter->second, true);
+#if defined(__llvm__)
+        mirroring_host_info_map_.erase(iter++);
+#else
         iter = mirroring_host_info_map_.erase(iter);
+#endif
       } else {
         ++iter;
       }
