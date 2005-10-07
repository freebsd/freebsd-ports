--- src/plugins/GUI/gui_userview.c.orig	Fri Oct  7 12:31:16 2005
+++ src/plugins/GUI/gui_userview.c	Fri Oct  7 12:34:25 2005
@@ -88,6 +88,8 @@
 			 GtkTreeIter * iter, gpointer data)
 {
 	GGaduContact *k = NULL;
+	gchar *markup_descr;
+	gchar *markup;
 
 	gtk_tree_model_get(model, iter, 2, &k, -1);
 
@@ -165,10 +167,10 @@
 		        }
 		    } 
 
-		    gchar *markup_descr = ggadu_config_var_get(gui_handler, "wrap_descr") ?
+		    markup_descr = ggadu_config_var_get(gui_handler, "wrap_descr") ?
 		                          g_markup_escape_text(descr, strlen(descr)) :
 			                  g_markup_escape_text(k->status_descr, strlen(k->status_descr));
-		    gchar *markup = g_strdup_printf("%s\n<small>%s</small>", k->nick, markup_descr);
+		    markup = g_strdup_printf("%s\n<small>%s</small>", k->nick, markup_descr);
 		    g_object_set(G_OBJECT(renderer), "text", NULL, "markup", markup, NULL);
 		    g_free(markup_descr);
 		    g_free(markup);
