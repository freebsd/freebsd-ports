diff src/pb_controller.cpp src/pb_controller.cpp
--- src/pb_controller.cpp
+++ src/pb_controller.cpp
@@ -287,6 +287,7 @@ void pb_controller::start_downloads() {
 		if (it->status() == DL_QUEUED) {
 			std::thread t {poddlthread(&(*it), cfg)};
 			--dl2start;
+			t.detach();
 		}
 	}
 }
