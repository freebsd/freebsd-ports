--- xs/GtkHTMLEmbedded.xs.orig	Sun Dec  1 21:06:22 2002
+++ xs/GtkHTMLEmbedded.xs	Sun Dec  1 21:06:29 2002
@@ -20,7 +20,7 @@
 	int	width
 	int	height
 	CODE:
-	RETVAL = GTK_HTML_EMBEDDED(gtk_html_embedded_new(classid, name, type, width, height));
+	RETVAL = (GtkHTMLEmbedded*)(gtk_html_embedded_new(classid, name, type, width, height));
 	OUTPUT:
 	RETVAL
 
