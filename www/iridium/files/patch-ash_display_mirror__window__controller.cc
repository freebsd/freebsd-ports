--- ash/display/mirror_window_controller.cc.orig	2019-03-11 22:00:51 UTC
+++ ash/display/mirror_window_controller.cc
@@ -274,7 +274,11 @@ void MirrorWindowController::UpdateWindow(
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
