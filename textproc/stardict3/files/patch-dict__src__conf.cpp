--- ./dict/src/conf.cpp.orig	2011-07-03 06:58:40.000000000 +0000
+++ ./dict/src/conf.cpp	2011-10-20 21:40:21.491156419 +0000
@@ -181,7 +181,7 @@
 #if defined(CONFIG_GPE)
 	add_entry("/apps/stardict/preferences/dictionary/url_open_command", std::string("gpe-mini-browser"));
 #else
-	add_entry("/apps/stardict/preferences/dictionary/url_open_command", std::string("firefox")); // absolute command
+	add_entry("/apps/stardict/preferences/dictionary/url_open_command", std::string("xdg-open")); // absolute command
 #endif
 #if defined(_WIN32) || defined(CONFIG_GNOME)
 	add_entry("/apps/stardict/preferences/dictionary/always_use_open_url_command", false);
