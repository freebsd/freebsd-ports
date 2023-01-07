--- gdk/glue/windowmanager.c.orig	2016-09-22 10:17:18 UTC
+++ gdk/glue/windowmanager.c
@@ -110,7 +110,7 @@ gtksharp_get_gdk_net_client_list (int *count)
 	list = g_malloc (*count * sizeof (gpointer));
 	/* Put all of the windows into a GList to return */
 	for (i = 0; i < *count; i ++) {
-		list [i] = data [i];
+		list [i] = (gpointer) data [i];
 		g_message ("WinID: %d", list [i]);
 	}
 
