--- libs/merge.c.orig	Thu Jan 16 01:40:06 2003
+++ libs/merge.c	Thu Jan 16 01:40:34 2003
@@ -192,6 +192,8 @@
 	char **lang_tab, *path;
 	int i, lang_num, count;
 	xmlDocPtr merged_tree, *tree_tab;
+
+	setenv("XML_CATALOG_FILES", SK_XML_CATALOGS, 1);
 	
 	lang_tab = sk_get_language_list();
 	
