--- gtksourceview/gtksourcebuffer.c.orig	Wed May  7 20:05:58 2003
+++ gtksourceview/gtksourcebuffer.c	Wed May  7 20:06:18 2003
@@ -687,9 +687,10 @@
 static void
 get_tags_func (GtkTextTag *tag, gpointer data)
 {
+    	GSList **list;
 	g_return_if_fail (data != NULL);
 
-	GSList **list = (GSList **) data;
+	list = (GSList **) data;
 
 	if (GTK_IS_SOURCE_TAG (tag))
 	{
