--- plugins/actions/insertsubtitlefromkeyframe/insertsubtitlefromkeyframe.cc.orig	2014-02-12 22:02:55 UTC
+++ plugins/actions/insertsubtitlefromkeyframe/insertsubtitlefromkeyframe.cc
@@ -103,7 +103,7 @@ public:
 		se_debug(SE_DEBUG_PLUGINS);
 
 		bool has_doc = (get_current_document() != NULL);
-		bool has_kf = (player()->get_keyframes());
+		bool has_kf = static_cast<bool>(player()->get_keyframes());
 		bool has_media = player()->get_state() != Player::NONE;
 
 		action_group->get_action("insert-subtitle-between-keyframes")->set_sensitive(has_doc && has_kf && has_media);
