--- ash/display/mirror_window_controller.cc.orig	2017-06-05 19:03:00 UTC
+++ ash/display/mirror_window_controller.cc
@@ -249,7 +249,11 @@ void MirrorWindowController::UpdateWindow(
                          return info.id() == iter->first;
                        }) == display_info_list.end()) {
         CloseAndDeleteHost(iter->second, true);
+#if defined(__llvm__)
+        mirroring_host_info_map_.erase(iter++);
+#else
         iter = mirroring_host_info_map_.erase(iter);
+#endif
       } else {
         ++iter;
       }
