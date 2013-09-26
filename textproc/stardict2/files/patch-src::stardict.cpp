--- ./src/stardict.cpp.orig	2006-07-02 23:19:31.000000000 -0700
+++ ./src/stardict.cpp	2013-09-05 17:40:53.829831298 -0700
@@ -873,7 +873,8 @@
 	gtk_widget_show_all(search_window);
 
 	//clock_t t=clock();
-	std::vector<gchar *> reslist[oLibs.ndicts()];
+	std::vector<gchar *> *reslist;
+	reslist = new std::vector<gchar *>[oLibs.ndicts()];
 	if (oLibs.LookupData(sWord, reslist, updateSearchDialog, &Dialog, &cancel)) {
 		oMidWin.oIndexWin.oListWin.list_word_type = LIST_WIN_DATA_LIST;
 		for (int i=0; i<oLibs.ndicts(); i++) {
