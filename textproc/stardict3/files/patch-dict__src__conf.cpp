--- ./dict/src/conf.cpp.orig	2012-12-10 14:44:32.000000000 +0000
+++ ./dict/src/conf.cpp	2013-02-24 14:11:08.724362041 +0000
@@ -184,13 +184,13 @@
 	add_entry("/apps/stardict/preferences/dictionary/sound_play_command", std::string("play")); // absolute command
 	add_entry("/apps/stardict/preferences/dictionary/always_use_sound_play_command", false);
 #else
-	add_entry("/apps/stardict/preferences/dictionary/sound_play_command", std::string("aplay")); // absolute command
+	add_entry("/apps/stardict/preferences/dictionary/sound_play_command", std::string("play")); // absolute command
 #endif
 	add_entry("/apps/stardict/preferences/dictionary/video_play_command", std::string("play")); // absolute command
 #if defined(CONFIG_GPE)
 	add_entry("/apps/stardict/preferences/dictionary/url_open_command", std::string("gpe-mini-browser"));
 #else
-	add_entry("/apps/stardict/preferences/dictionary/url_open_command", std::string("firefox")); // absolute command
+	add_entry("/apps/stardict/preferences/dictionary/url_open_command", std::string("xdg-open")); // absolute command
 #endif
 #if defined(_WIN32) || defined(CONFIG_GNOME)
 	add_entry("/apps/stardict/preferences/dictionary/always_use_open_url_command", false);
