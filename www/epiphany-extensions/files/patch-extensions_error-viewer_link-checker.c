--- extensions/error-viewer/link-checker.c.orig	Sun Mar  7 20:04:15 2004
+++ extensions/error-viewer/link-checker.c	Sun Mar  7 20:04:39 2004
@@ -111,10 +111,10 @@
 static gboolean
 link_checker_append_internal (gpointer data)
 {
+	LinkCheckerAppendCBData *append_data;
 	g_return_if_fail (data != NULL);
 
-	LinkCheckerAppendCBData *append_data =
-		(LinkCheckerAppendCBData *) data;
+	append_data = (LinkCheckerAppendCBData *) data;
 
 	g_return_if_fail (IS_LINK_CHECKER (append_data->checker));
 	g_return_if_fail (IS_ERROR_VIEWER
