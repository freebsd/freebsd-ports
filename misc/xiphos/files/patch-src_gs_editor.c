--- src/gs_editor.c.orig	Fri Feb 28 17:32:42 2003
+++ src/gs_editor.c	Fri Feb 28 17:33:19 2003
@@ -1252,6 +1252,10 @@
 		   GSHTMLEditorControlData * ecd)
 {
 	gchar buf[256], *target = "";
+#ifdef USE_GTKHTML1
+	const gchar *url;
+	const gchar *text;
+#endif
 	
 	HTMLEngine *e = ecd->html->engine;	
 	if (strlen(linkmod))
@@ -1260,8 +1264,6 @@
 		sprintf(buf, "passage=%s", linkref);
 	
 #ifdef USE_GTKHTML1
-	const gchar *url;
-	const gchar *text;
 	url = buf;
 	text = linkref;
 	if (url && text && *url && *text) {
