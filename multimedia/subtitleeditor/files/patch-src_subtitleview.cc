--- src/subtitleview.cc.orig	2014-02-12 22:02:59 UTC
+++ src/subtitleview.cc
@@ -1370,7 +1370,7 @@ bool SubtitleView::on_key_press_event(Gd
 	{
 		int num;
 		std::istringstream ss(event->string);
-		bool is_num = ss >> num != 0; 
+		bool is_num = static_cast<bool>(ss >> num);
 		// Update only if it's different
 		if(is_num != get_enable_search())
 			set_enable_search(is_num);
