--- src/readword.cpp.orig	Sat Nov 27 22:35:44 2004
+++ src/readword.cpp	Sat Nov 27 22:36:00 2004
@@ -18,7 +18,7 @@
 	have_data_file = g_file_test(filename, G_FILE_TEST_EXISTS);
 	g_free(filename);
 #else
-	have_data_file = g_file_test("/usr/share/WyabdcRealPeopleTTS", G_FILE_TEST_EXISTS);
+	have_data_file = g_file_test("/usr/local/share/WyabdcRealPeopleTTS", G_FILE_TEST_EXISTS);
 #endif
 }
 
@@ -34,7 +34,7 @@
 #ifdef _WIN32
 		gchar *filename = g_strdup_printf("%s/WyabdcRealPeopleTTS/%c/%s.wav", stardict_data_dir, lowerword[0],lowerword);
 #else
-		gchar *filename = g_strdup_printf("/usr/share/WyabdcRealPeopleTTS/%c/%s.wav", lowerword[0],lowerword);		
+		gchar *filename = g_strdup_printf("/usr/local/share/WyabdcRealPeopleTTS/%c/%s.wav", lowerword[0],lowerword);		
 #endif
 		return_val = g_file_test(filename, G_FILE_TEST_EXISTS);
 		g_free(filename);
@@ -56,7 +56,7 @@
 		filename = g_strdup_printf("%s/WyabdcRealPeopleTTS/%c/%s.wav", stardict_data_dir, lowerword[0],lowerword);
 		PlaySound(filename, 0, SND_ASYNC | SND_FILENAME);
 #else
-		filename = g_strdup_printf("/usr/share/WyabdcRealPeopleTTS/%c/%s.wav", lowerword[0],lowerword);		
+		filename = g_strdup_printf("/usr/local/share/WyabdcRealPeopleTTS/%c/%s.wav", lowerword[0],lowerword);		
 		gnome_sound_play(filename);
 #endif
 		g_free(filename);
