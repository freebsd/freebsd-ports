--- src/actions/kz-actions.c.orig	Fri Oct 29 23:26:27 2004
+++ src/actions/kz-actions.c	Fri Oct 29 23:29:21 2004
@@ -1500,10 +1500,10 @@
 	/* windows */
 	for (node = list; node; node = g_list_next(node))
 	{
+		KzWindow *window;
 		GList *tabs, *tabnode;
 		KzBookmark *window_bookmark = KZ_BOOKMARK(node->data);
 		tabs = kz_bookmark_get_children(window_bookmark);
-		KzWindow *window;
 
 		if (!window_node)
 		{
