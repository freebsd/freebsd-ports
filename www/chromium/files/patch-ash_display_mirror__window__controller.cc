--- ash/display/mirror_window_controller.cc.orig	2017-01-26 00:49:06 UTC
+++ ash/display/mirror_window_controller.cc
@@ -250,7 +250,11 @@ void MirrorWindowController::UpdateWindo
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
