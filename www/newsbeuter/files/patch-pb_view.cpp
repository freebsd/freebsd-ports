diff src/pb_view.cpp src/pb_view.cpp
--- src/pb_view.cpp
+++ src/pb_view.cpp
@@ -111,6 +111,7 @@ void pb_view::run(bool auto_download) {
 			if (idx != -1) {
 				if (ctrl->downloads()[idx].status() != DL_DOWNLOADING) {
 					std::thread t {poddlthread(&ctrl->downloads()[idx], ctrl->get_cfgcont())};
+					t.detach();
 				}
 			}
 		}
