--- tests/t_lookupdata.cpp.orig	2006-06-19 00:16:21.000000000 -0700
+++ tests/t_lookupdata.cpp	2013-09-26 11:31:36.077140174 -0700
@@ -18,7 +18,8 @@
 	
 	Libs libs(NULL, false, false, 0);
 	libs.load(dirs, List(), List());
-	std::vector<gchar *> reslist[libs.ndicts()];
+	std::vector<gchar *> *reslist;
+	reslist = new std::vector<gchar *>[libs.ndicts()];
 	if (libs.LookupData("letter", reslist, NULL, NULL, NULL)) 
 		return EXIT_SUCCESS;
 	else
