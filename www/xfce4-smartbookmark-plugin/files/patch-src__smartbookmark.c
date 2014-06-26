--- ./src/smartbookmark.c.orig	2013-01-03 21:18:38.000000000 +0000
+++ ./src/smartbookmark.c	2014-06-02 19:08:44.000000000 +0000
@@ -183,9 +183,9 @@
     box = gtk_vbox_new(FALSE, 0);
 
     /* default options */
-    search->url = "http://bugs.debian.org/";
-    search->label_text = "BTS";
-    search->size = 5;
+    search->url = "https://bugs.freebsd.org/bugzilla/";
+    search->label_text = "Bugzilla";
+    search->size = 10;
     search->hide_label = FALSE;
     /* read config file options */
     filename = xfce_panel_plugin_save_location(plugin, TRUE);
@@ -255,9 +255,9 @@
     if( (rcfile = xfce_rc_simple_open(filename, TRUE) ))
     {
         xfce_rc_set_group(rcfile, NULL);
-        search->url = g_strdup(xfce_rc_read_entry(rcfile,"url","http://bugs.debian.org/"));
-        search->label_text = g_strdup(xfce_rc_read_entry(rcfile,"value","DBS"));
-        search->size = xfce_rc_read_int_entry(rcfile, "size", 5);
+        search->url = g_strdup(xfce_rc_read_entry(rcfile,"url","https://bugs.freebsd.org/bugzilla/"));
+        search->label_text = g_strdup(xfce_rc_read_entry(rcfile,"value","Bugzilla"));
+        search->size = xfce_rc_read_int_entry(rcfile, "size", 10);
         search->hide_label = xfce_rc_read_bool_entry(rcfile, "hidelabel", FALSE);
     }
 }
