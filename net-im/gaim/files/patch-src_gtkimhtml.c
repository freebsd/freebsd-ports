--- src/gtkimhtml.c.orig	Sun May 30 18:17:14 2004
+++ src/gtkimhtml.c	Sun May 30 18:19:47 2004
@@ -782,7 +782,7 @@
 	if (selection_data->length >= 2 &&
 		(*(guint16 *)text == 0xfeff || *(guint16 *)text == 0xfffe)) {
 		/* This is UCS-2 */
-		char *tmp;
+		/*char *tmp;*/
 		char *utf8 = g_convert(text, selection_data->length, "UTF-8", "UCS-2", NULL, NULL, NULL);
 		g_free(text);
 		text = utf8;
@@ -790,8 +790,8 @@
 			gaim_debug_warning("gtkimhtml", "g_convert from UCS-2 failed in paste_received_cb\n");
 			return;
 		}
-		tmp = g_utf8_next_char(text);
-		memmove(text, tmp, strlen(tmp) + 1);
+		/*tmp = g_utf8_next_char(text);*/
+		/*memmove(text, tmp, strlen(tmp) + 1);*/
 	}
 
 	if (!(*text) || !g_utf8_validate(text, -1, NULL)) {
