--- src/readword.cpp.orig	Mon Jul 18 21:06:15 2005
+++ src/readword.cpp	Thu Aug  4 16:42:21 2005
@@ -17,7 +17,7 @@
 	  g_file_test((gStarDictDataDir+G_DIR_SEPARATOR+"WyabdcRealPeopleTTS").c_str(), 
 		      G_FILE_TEST_EXISTS);
 #else
-	have_data_file = g_file_test("/usr/share/WyabdcRealPeopleTTS", G_FILE_TEST_EXISTS);
+	have_data_file = g_file_test("/usr/local/share/WyabdcRealPeopleTTS", G_FILE_TEST_EXISTS);
 #endif
 }
 
@@ -35,7 +35,7 @@
     filename = gStarDictDataDir+"/WyabdcRealPeopleTTS/"+
       lowerword[0]+"/"+lowerword+".wav";
 #else
-    filename = std::string("/usr/share/WyabdcRealPeopleTTS/")+lowerword[0]+"/"+
+    filename = std::string("/usr/local/share/WyabdcRealPeopleTTS/")+lowerword[0]+"/"+
       lowerword+".wav";
 #endif
     return_val = g_file_test(filename.c_str(), G_FILE_TEST_EXISTS);
@@ -58,7 +58,7 @@
     filename = gStarDictDataDir+"/WyabdcRealPeopleTTS/"+
       lowerword[0]+"/"+lowerword+".wav";
 #else
-    filename = std::string("/usr/share/WyabdcRealPeopleTTS/")+
+    filename = std::string("/usr/local/share/WyabdcRealPeopleTTS/")+
       lowerword[0]+"/"+lowerword+".wav";
 #endif
     play_wav_file(filename.c_str());
