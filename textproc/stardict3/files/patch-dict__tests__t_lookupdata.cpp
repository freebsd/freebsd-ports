--- ./dict/tests/t_lookupdata.cpp.orig	2012-12-11 08:15:24.000000000 +0000
+++ ./dict/tests/t_lookupdata.cpp	2012-12-11 08:29:56.172016591 +0000
@@ -38,8 +38,8 @@
 	List dict_list;
 	libs.load(dict_list);
 	std::vector<InstantDictIndex> dictmask;
-	std::vector<gchar *> reslist[dictmask.size()];
-	if (libs.LookupData("letter", reslist, NULL, NULL, NULL, dictmask)) 
+	std::vector< std::vector<gchar *> > reslist(dictmask.size());
+	if (libs.LookupData("letter", &reslist[0], NULL, NULL, NULL, dictmask)) 
 		return EXIT_SUCCESS;
 	else
 		return EXIT_FAILURE;
