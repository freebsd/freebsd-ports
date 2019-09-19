--- panel-plugin/wavelan.c.orig	2019-08-13 10:29:17 UTC
+++ panel-plugin/wavelan.c
@@ -108,11 +108,11 @@ wavelan_set_state(t_wavelan *wavelan, gint state)
 
   if (wavelan->signal_colors) {
      /* set color */
-   if (state > 70)
+   if (state > 75)
     gdk_rgba_parse(&color, signal_color_strong);
-   else if (state > 55)
+   else if (state > 50)
     gdk_rgba_parse(&color, signal_color_good);
-   else if (state > 40)
+   else if (state > 25)
     gdk_rgba_parse(&color, signal_color_weak);
    else
     gdk_rgba_parse(&color, signal_color_bad);
@@ -357,11 +357,13 @@ wavelan_new(XfcePanelPlugin *plugin)
 
   /* setup progressbar */
   wavelan->signal = gtk_progress_bar_new();
+#if GTK_CHECK_VERSION (3, 16, 0)
   wavelan->css_provider = gtk_css_provider_new ();
   gtk_style_context_add_provider (
       GTK_STYLE_CONTEXT (gtk_widget_get_style_context (GTK_WIDGET (wavelan->signal))),
       GTK_STYLE_PROVIDER (wavelan->css_provider),
       GTK_STYLE_PROVIDER_PRIORITY_APPLICATION);
+#endif
   wavelan->image = GTK_WIDGET(xfce_panel_image_new_from_source("network-wireless"));
 
   gtk_box_pack_start(GTK_BOX(wavelan->box), GTK_WIDGET(wavelan->image), FALSE, FALSE, 0);
