--- gok/gok-scanner.c.orig	Mon Sep 29 21:04:52 2003
+++ gok/gok-scanner.c	Mon Sep 29 21:05:05 2003
@@ -220,10 +220,11 @@
 	xmlNode *retval = NULL;
 	int      target_lang_len = strlen ((char *)target_lang);
 	gboolean lang_is_matched = FALSE;	
+	gboolean is_lang_match, is_perfect_match;
 
 	gok_log_enter();
-	gboolean is_lang_match = FALSE;
-	gboolean is_perfect_match = FALSE;
+	is_lang_match = FALSE;
+	is_perfect_match = FALSE;
 	/* loop through the document looking for the name string */
 	while (pNode != NULL)
 	{
