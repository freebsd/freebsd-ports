--- ash/display/mirror_window_controller.cc.orig	2022-10-29 17:50:56 UTC
+++ ash/display/mirror_window_controller.cc
@@ -295,7 +295,11 @@ void MirrorWindowController::UpdateWindow(
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
