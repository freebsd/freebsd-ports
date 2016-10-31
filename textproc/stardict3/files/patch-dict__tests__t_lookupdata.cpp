--- dict/tests/t_lookupdata.cpp.orig	2013-11-18 08:10:23 UTC
+++ dict/tests/t_lookupdata.cpp
@@ -38,9 +38,8 @@ int main(int argc, char *argv[])
 	List dict_list;
 	libs.load(dict_list);
 	std::vector<InstantDictIndex> dictmask;
-	size_t dictmask_size = dictmask.size();
-	std::vector<gchar *> reslist[dictmask_size];
-	if (libs.LookupData("letter", reslist, NULL, NULL, NULL, dictmask)) 
+	std::vector< std::vector<gchar *> > reslist(dictmask.size());
+	if (libs.LookupData("letter", &reslist[0], NULL, NULL, NULL, dictmask)) 
 		return EXIT_SUCCESS;
 	else
 		return EXIT_FAILURE;
