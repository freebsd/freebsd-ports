--- src/htmlview.c.old	Tue Aug 17 23:56:37 2004
+++ src/htmlview.c	Tue Aug 17 23:56:57 2004
@@ -59,7 +59,7 @@
 
 HtmlView *htmlview_create(void)
 {
-	HtmlView *htmlview;
+	HtmlView *htmlview = NULL;
 #ifdef USE_MOZILLA
 	GtkMozEmbed *mozwin;
 	gchar *mozpat;
