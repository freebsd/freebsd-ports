--- src/main.c.orig	Sat Aug 28 00:28:30 2004
+++ src/main.c	Sat Aug 28 00:28:47 2004
@@ -318,6 +318,7 @@
 		GList *list = kz_window_get_window_list();
 		KzWindow *kz;
 		gchar **argv;
+		gchar *uri;
 		gint i;
 
 		if (!list || !list->data || !KZ_IS_WINDOW(list->data)) return;
@@ -338,7 +339,7 @@
 				continue;
 			}
 
-			gchar *uri = complement_scheme(argv[i]);
+			uri = complement_scheme(argv[i]);
 			kz_window_open_new_tab(kz, uri);
 			g_free(uri);
 		}
