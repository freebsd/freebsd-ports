--- panel-plugin/wavelan.c.orig	2016-10-29 06:46:02 UTC
+++ panel-plugin/wavelan.c
@@ -64,6 +64,9 @@ typedef struct
   GtkWidget *image;
   GtkWidget *signal;
   GtkWidget *tooltip_text;
+#if GTK_CHECK_VERSION (3, 16, 0)
+  GtkCssProvider *css_provider;
+#endif
 
   XfcePanelPlugin *plugin;
   
@@ -77,7 +80,6 @@ wavelan_set_state(t_wavelan *wavelan, gint state)
 {  
   GdkRGBA color;
 #if GTK_CHECK_VERSION (3, 16, 0)
-  GtkCssProvider *css_provider;
   gchar *css;
 #endif
 
@@ -99,11 +101,11 @@ wavelan_set_state(t_wavelan *wavelan, gint state)
 
    if (wavelan->signal_colors) {
     /* set color */
-     if (state > 70)
+     if (state > 75)
       gdk_rgba_parse(&color, signal_color_strong);
-     else if (state > 55)
+     else if (state > 50)
       gdk_rgba_parse(&color, signal_color_good);
-     else if (state > 40)
+     else if (state > 25)
       gdk_rgba_parse(&color, signal_color_weak);
      else
       gdk_rgba_parse(&color, signal_color_bad);
@@ -118,12 +120,7 @@ wavelan_set_state(t_wavelan *wavelan, gint state)
 #endif
                            gdk_rgba_to_string(&color));
      /* Setup Gtk style */
-     css_provider = gtk_css_provider_new ();
-     gtk_css_provider_load_from_data (css_provider, css, strlen(css), NULL);
-     gtk_style_context_add_provider (
-         GTK_STYLE_CONTEXT (gtk_widget_get_style_context (GTK_WIDGET (wavelan->signal))),
-         GTK_STYLE_PROVIDER (css_provider),
-         GTK_STYLE_PROVIDER_PRIORITY_APPLICATION);
+     gtk_css_provider_load_from_data (wavelan->css_provider, css, strlen(css), NULL);
      g_free(css);
 #else
      gtk_widget_override_background_color(GTK_WIDGET(wavelan->signal),
@@ -183,7 +180,15 @@ wavelan_timer(gpointer data)
       }
     }
     else {
-      wavelan_set_state(wavelan, stats.ws_quality);
+      /*
+       * Usual formula is: qual = 4 * (signal - noise)
+       * where noise is typically about -96dBm, but we don't have
+       * the actual noise value here, so approximate one.
+       */
+      if (strcmp(stats.ws_qunit, "dBm") == 0)
+        wavelan_set_state(wavelan, 4 * (stats.ws_quality - (-96)));
+      else
+        wavelan_set_state(wavelan, stats.ws_quality);
 
       if (strlen(stats.ws_netname) > 0)
         /* Translators: net_name: quality quality_unit at rate Mb/s*/
@@ -338,6 +343,13 @@ wavelan_new(XfcePanelPlugin *plugin)
 
   /* setup progressbar */
   wavelan->signal = gtk_progress_bar_new();
+#if GTK_CHECK_VERSION (3, 16, 0)
+  wavelan->css_provider = gtk_css_provider_new ();
+  gtk_style_context_add_provider (
+      GTK_STYLE_CONTEXT (gtk_widget_get_style_context (GTK_WIDGET (wavelan->signal))),
+      GTK_STYLE_PROVIDER (wavelan->css_provider),
+      GTK_STYLE_PROVIDER_PRIORITY_APPLICATION);
+#endif
   wavelan->image = GTK_WIDGET(xfce_panel_image_new_from_source("network-wireless"));
 
   gtk_box_pack_start(GTK_BOX(wavelan->box), GTK_WIDGET(wavelan->image), FALSE, FALSE, 0);
