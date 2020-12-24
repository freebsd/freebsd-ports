--- src/smartbookmark.c.orig	2020-12-24 16:01:51 UTC
+++ src/smartbookmark.c
@@ -173,10 +173,10 @@ static t_search *search_new(XfcePanelPlugin *plugin)
     gtk_widget_set_valign(GTK_WIDGET(search->box), GTK_ALIGN_CENTER);
 
     /* default options */
-    search->url = "https://bugs.debian.org/";
-    search->label_text = "BTS";
-    search->size = 5;
-    search->hide_label = FALSE;
+    search->url = "https://bugs.freebsd.org/bugzilla/buglist.cgi?quicksearch=";
+    search->label_text = "FreeBSD";
+    search->size = 10;
+    search->hide_label = TRUE;
     /* read config file options */
     filename = xfce_panel_plugin_save_location(plugin, TRUE);
     search_read_config(search, filename);
@@ -209,10 +209,10 @@ static void search_read_config(t_search *search, const
     if( (rcfile = xfce_rc_simple_open(filename, TRUE) ))
     {
         xfce_rc_set_group(rcfile, NULL);
-        search->url = g_strdup(xfce_rc_read_entry(rcfile,"url","https://bugs.debian.org/"));
-        search->label_text = g_strdup(xfce_rc_read_entry(rcfile,"value","DBS"));
-        search->size = xfce_rc_read_int_entry(rcfile, "size", 5);
-        search->hide_label = xfce_rc_read_bool_entry(rcfile, "hidelabel", FALSE);
+        search->url = g_strdup(xfce_rc_read_entry(rcfile,"url","https://bugs.freebsd.org/bugzilla/buglist.cgi?quicksearch="));
+        search->label_text = g_strdup(xfce_rc_read_entry(rcfile,"value","FreeBSD"));
+        search->size = xfce_rc_read_int_entry(rcfile, "size", 10);
+        search->hide_label = xfce_rc_read_bool_entry(rcfile, "hidelabel", TRUE);
     }
 }
 
