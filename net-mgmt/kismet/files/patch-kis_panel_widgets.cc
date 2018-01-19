--- kis_panel_widgets.cc.orig	2016-07-02 18:06:10 UTC
+++ kis_panel_widgets.cc
@@ -2582,7 +2582,7 @@ int Kis_Single_Input::KeyPress(int in_key) {
 	// and if we have room, insert it and scroll to the right
 	if ((int) text.length() < max_len && 
 		filter_map.find(in_key) != filter_map.end()) {
-		char ins[2] = { in_key, 0 };
+		char ins[2] = { (char) in_key, (char) 0 };
 		text.insert(inp_pos, ins);
 		inp_pos++;
 
