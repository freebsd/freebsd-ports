--- ash/display/mirror_window_controller.cc.orig	2020-05-13 18:39:35 UTC
+++ ash/display/mirror_window_controller.cc
@@ -275,7 +275,11 @@ void MirrorWindowController::UpdateWindow(
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
