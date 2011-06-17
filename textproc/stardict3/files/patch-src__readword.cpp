--- ./src/readword.cpp.orig	2010-12-17 19:58:59.000000000 +0300
+++ ./src/readword.cpp	2011-06-18 00:38:15.560473773 +0400
@@ -78,7 +78,7 @@
 		std::string filename;
 		std::list<std::string>::const_iterator it;
 		for (it=ttspath.begin(); it!=ttspath.end(); ++it) {
-			filename = build_path(*it, lowerword[0] + G_DIR_SEPARATOR_S + lowerword + ".wav");
+			filename = build_path(*it, std::string(1,lowerword[0]) + G_DIR_SEPARATOR_S + lowerword + ".wav");
 			return_val = g_file_test(filename.c_str(), G_FILE_TEST_EXISTS);
 			if (return_val)
 				break;
@@ -109,7 +109,7 @@
 		std::string filename;
 		std::list<std::string>::const_iterator it;
 		for (it=ttspath.begin(); it!=ttspath.end(); ++it) {
-			filename = build_path(*it, lowerword[0] + G_DIR_SEPARATOR_S + lowerword + ".wav");
+			filename = build_path(*it, std::string(1,lowerword[0]) + G_DIR_SEPARATOR_S + lowerword + ".wav");
 			if (g_file_test(filename.c_str(), G_FILE_TEST_EXISTS)) {
 				play_sound_file(filename);
 				break;
