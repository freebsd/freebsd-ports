--- plugins/actions/keyframesmanagement/keyframesmanagement.cc.orig	2014-02-12 22:02:57 UTC
+++ plugins/actions/keyframesmanagement/keyframesmanagement.cc
@@ -223,7 +223,7 @@ public:
 		se_debug(SE_DEBUG_PLUGINS);
 		
 		bool has_doc = (get_current_document() != NULL);
-		bool has_kf = (player()->get_keyframes());
+		bool has_kf = static_cast<bool>(player()->get_keyframes());
 		bool has_media = player()->get_state() != Player::NONE;
 
 #define SET_SENSITIVE(action, state) { Glib::RefPtr<Gtk::Action> act = action_group->get_action(action); if(act) act->set_sensitive(state); else g_warning(action); }
