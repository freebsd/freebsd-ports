--- src/archive_viewer.c.orig	Sat Jan  8 18:43:37 2005
+++ src/archive_viewer.c	Sat Jan  8 18:44:12 2005
@@ -340,8 +340,8 @@
 		return;
 	}
 	for (node = node->children; node; node = node->next) {
-		foo_debug ("Reading item %s\n", node->name);
 		KfArchiveConversation *conversation = NULL;
+		foo_debug ("Reading item %s\n", node->name);
 		if (xmlStrcmp (node->name, (const xmlChar *) "item") == 0) {
 			GtkTreeIter iter;
 			xmlChar *name;
