--- src/htmltext.c.orig	Wed Dec  8 01:45:57 2004
+++ src/htmltext.c	Wed Dec  8 01:46:10 2004
@@ -2433,10 +2433,11 @@
 gsize
 html_text_sanitize (const gchar **str, gint *len)
 {
+	gchar *end;
 	g_return_val_if_fail (str != NULL, 0);
 	g_return_val_if_fail (len != NULL, 0);
 	
-	gchar *end = offset_to_pointer_validated (*str, *len, len);
+	end = offset_to_pointer_validated (*str, *len, len);
 	if (end) {
 		return end - *str;
 	} else {
