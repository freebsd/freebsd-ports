--- src/conf.cpp.orig	Mon Jul 10 05:23:39 2006
+++ src/conf.cpp	Mon Jul 10 05:24:36 2006
@@ -93,7 +93,7 @@
 #ifdef _WIN32
 	add_entry("/apps/stardict/preferences/dictionary/tts_path", std::string("C:\\Program Files\\WyabdcRealPeopleTTS\nC:\\Program Files\\OtdRealPeopleTTS\nWyabdcRealPeopleTTS\nOtdRealPeopleTTS"));
 #else
-	add_entry("/apps/stardict/preferences/dictionary/tts_path", std::string("/usr/share/WyabdcRealPeopleTTS\n/usr/share/OtdRealPeopleTTS"));
+	add_entry("/apps/stardict/preferences/dictionary/tts_path", std::string("/usr/local/share/WyabdcRealPeopleTTS\n/usr/local/share/OtdRealPeopleTTS"));
 #endif
 	add_entry("/apps/stardict/preferences/dictionary/history", get_default_history_filename());
 	add_entry("/apps/stardict/preferences/dictionary/only_export_word", true);
