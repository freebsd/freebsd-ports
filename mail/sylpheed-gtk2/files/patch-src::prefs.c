--- src/prefs.c.orig	Fri Jan 23 12:08:46 2004
+++ src/prefs.c	Fri Jan 23 12:16:37 2004
@@ -109,17 +109,18 @@
 		case P_STRING:
 		{
 #warning FIXME_GTK2
-			gchar *tmp;
+			gchar *tmp = NULL;
 
-			tmp = *value ?
-				conv_codeset_strdup(value,
-						    conv_get_current_charset_str(),
-						    CS_UTF_8)
-				: g_strdup("");
-			if (!tmp) {
-				g_warning("faild to convert character set.");
-				tmp = g_strdup(value);
+			if (*value) {
+				tmp = conv_codeset_strdup(value,
+							  conv_get_current_charset_str(),
+							  CS_UTF_8);
+				if (!tmp) {
+					g_warning("failed to convert character set.");
+					tmp = g_strdup(value);
+				}
 			}
+			
 			g_free(*((gchar **)param[i].data));
 			*((gchar **)param[i].data) = tmp;
 			break;
