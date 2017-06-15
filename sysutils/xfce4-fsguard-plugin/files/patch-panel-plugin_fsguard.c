--- panel-plugin/fsguard.c.orig	2016-10-29 06:43:10 UTC
+++ panel-plugin/fsguard.c
@@ -70,6 +70,7 @@ typedef struct
     XfcePanelPlugin    *plugin;
     gboolean            seen;
     gint                icon_id;
+    gchar              *css_class;
     gint                timeout;
     guint               limit_warning;
     guint               limit_urgent;
@@ -135,6 +136,7 @@ fsguard_set_icon (FsGuard *fsguard, gint
     if (id == fsguard->icon_id)
         return;
 
+    DBG ("icon id: new=%d, cur=%d", id, fsguard->icon_id);
     fsguard->icon_id = id;
     size = xfce_panel_plugin_get_size (fsguard->plugin);
     size /= xfce_panel_plugin_get_nrows (fsguard->plugin);
@@ -177,7 +179,7 @@ fsguard_refresh_icon (FsGuard *fsguard)
 }
 
 static void
-fsguard_refresh_monitor (FsGuard *fsguard)
+fsguard_refresh_monitor_color (FsGuard *fsguard, gchar *css_class)
 {
     GdkRGBA             color;
 
@@ -197,23 +199,15 @@ fsguard_refresh_monitor (FsGuard *fsguar
     }
 
 #if GTK_CHECK_VERSION (3, 16, 0)
-    GtkCssProvider *css_provider;
-#if GTK_CHECK_VERSION (3, 20, 0)
-    gchar * css = g_strdup_printf("progressbar trough { min-width: 4px; min-height: 4px; } \
-                                   progressbar progress { min-width: 4px; min-height: 4px; \
-                                                          background-color: %s; background-image: none; }",
-#else
-    gchar * css = g_strdup_printf(".progressbar { background-color: %s; background-image: none; }",
-#endif
-                                  gdk_rgba_to_string(&color));
-    /* Setup Gtk style */
-    css_provider = gtk_css_provider_new ();
-    gtk_css_provider_load_from_data (css_provider, css, strlen(css), NULL);
-    gtk_style_context_add_provider (
-        GTK_STYLE_CONTEXT (gtk_widget_get_style_context (GTK_WIDGET (fsguard->progress_bar))),
-        GTK_STYLE_PROVIDER (css_provider),
-        GTK_STYLE_PROVIDER_PRIORITY_APPLICATION);
-    g_free(css);
+    DBG("removing class %s, adding %s", fsguard->css_class, css_class);
+    gtk_style_context_remove_class (
+        GTK_STYLE_CONTEXT(gtk_widget_get_style_context (GTK_WIDGET (fsguard->progress_bar))),
+        fsguard->css_class);
+    gtk_style_context_add_class (
+        GTK_STYLE_CONTEXT(gtk_widget_get_style_context (GTK_WIDGET (fsguard->progress_bar))),
+        css_class);
+    g_free(fsguard->css_class);
+    fsguard->css_class = g_strdup(css_class);
 #else
     gtk_widget_override_background_color (GTK_WIDGET (fsguard->progress_bar),
                           GTK_STATE_PRELIGHT,
@@ -270,6 +264,7 @@ fsguard_check_fs (FsGuard *fsguard)
     float               totalblocks = 0;
     long                blocksize = 0;
     int                 err;
+    gchar              *css_class = "normal";
     gchar               msg_size[100], msg_total_size[100], msg[100];
     gint                icon_id = ICON_INSENSITIVE;
     static struct statfs fsd;
@@ -285,10 +280,13 @@ fsguard_check_fs (FsGuard *fsguard)
 
         if (freespace > (total * fsguard->limit_warning / 100)) {
             icon_id = ICON_NORMAL;
+            css_class = "normal";
         } else if (freespace > (total * fsguard->limit_urgent / 100) && freespace <= (total * fsguard->limit_warning / 100)) {
             icon_id = ICON_WARNING;
+            css_class = "warning";
         } else {
             icon_id = ICON_URGENT;
+            css_class = "urgent";
         }
     }
         g_snprintf (msg, sizeof (msg),
@@ -316,7 +314,8 @@ fsguard_check_fs (FsGuard *fsguard)
     if (fsguard->show_progress_bar) {
         gtk_progress_bar_set_fraction (GTK_PROGRESS_BAR(fsguard->progress_bar),
                                        (total > 0 ) ? 1.0 - (freespace / total) : 0.0);
-        fsguard_refresh_monitor (fsguard);
+        if (icon_id != fsguard->icon_id)
+            fsguard_refresh_monitor_color (fsguard, css_class);
     }
 
     gtk_widget_set_tooltip_text(fsguard->ebox, msg);
@@ -347,6 +346,7 @@ fsguard_read_config (FsGuard *fsguard)
     fsguard->name               = g_strdup ("");
     fsguard->show_name          = FALSE;
     fsguard->path               = g_strdup ("/");
+    fsguard->css_class          = g_strdup ("normal");
     fsguard->show_size          = TRUE;
     fsguard->show_progress_bar  = TRUE;
     fsguard->hide_button        = FALSE;
@@ -406,6 +406,9 @@ fsguard_write_config (XfcePanelPlugin *p
 static FsGuard *
 fsguard_new (XfcePanelPlugin *plugin)
 {
+#if GTK_CHECK_VERSION (3, 16, 0)
+    GtkCssProvider *css_provider;
+#endif
     FsGuard *fsguard = g_new0(FsGuard, 1);
 
     fsguard->plugin = plugin;
@@ -429,6 +432,37 @@ fsguard_new (XfcePanelPlugin *plugin)
     fsguard->icon_panel = gtk_image_new ();
 
     fsguard->progress_bar = gtk_progress_bar_new ();
+#if GTK_CHECK_VERSION (3, 16, 0)
+    css_provider = gtk_css_provider_new ();
+#if GTK_CHECK_VERSION (3, 20, 0)
+        gtk_css_provider_load_from_data (css_provider, "\
+            progressbar.horizontal trough { min-height: 4px; }\
+            progressbar.horizontal progress { min-height: 4px; }\
+            progressbar.vertical trough { min-width: 4px; }\
+            progressbar.vertical progress { min-width: 4px; }\
+            .normal progress { background-color: " COLOR_NORMAL " ; background-image: none; }\
+            .warning progress { background-color: " COLOR_WARNING " ; background-image: none; }\
+            .urgent progress { background-color: " COLOR_URGENT " ; background-image: none; }",
+             -1, NULL);
+#else
+        gtk_css_provider_load_from_data (css_provider, "\
+            .progressbar.horizontal trough { min-height: 4px; }\
+            .progressbar.horizontal progress { min-height: 4px; }\
+            .progressbar.vertical trough { min-width: 4px; }\
+            .progressbar.vertical progress { min-width: 4px; }\
+            .normal progress { background-color: " COLOR_NORMAL " ; background-image: none; }\
+            .warning progress { background-color: " COLOR_WARNING " ; background-image: none; }\
+            .urgent progress { background-color: " COLOR_URGENT " ; background-image: none; }",
+             -1, NULL);
+#endif
+    gtk_style_context_add_provider (
+        GTK_STYLE_CONTEXT (gtk_widget_get_style_context (GTK_WIDGET (fsguard->progress_bar))),
+        GTK_STYLE_PROVIDER (css_provider),
+        GTK_STYLE_PROVIDER_PRIORITY_APPLICATION);
+    gtk_style_context_add_class (
+        GTK_STYLE_CONTEXT(gtk_widget_get_style_context (GTK_WIDGET (fsguard->progress_bar))),
+        fsguard->css_class);
+#endif
     gtk_progress_bar_set_fraction (GTK_PROGRESS_BAR(fsguard->progress_bar), 0.0);
     gtk_progress_bar_set_inverted (GTK_PROGRESS_BAR(fsguard->progress_bar), (orientation == GTK_ORIENTATION_HORIZONTAL));
     gtk_orientable_set_orientation (GTK_ORIENTABLE(fsguard->progress_bar), !orientation);
