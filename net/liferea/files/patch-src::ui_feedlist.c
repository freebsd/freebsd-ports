--- src/ui_feedlist.c.orig	Mon May 24 19:48:01 2004
+++ src/ui_feedlist.c	Mon May 24 19:48:45 2004
@@ -519,6 +519,9 @@
 	feedPtr			fp;
 	gchar			*data, *tmp;
 	
+	int pos;
+	folderPtr parent;
+	
 	debug_enter("ui_feedlist_new_subscription");	
 	
 	/* directly download (do not use update queue to avoid
@@ -531,9 +534,7 @@
 	data = downloadURL(request);	/* FIXME: The downloading should not block? */
 
 	/* determine feed type if necessary */	
-	int pos;
-	folderPtr parent;
-	
+
 	fp = feed_new();
 	tmp = conf_new_id();
 	feed_set_id(fp, tmp);
