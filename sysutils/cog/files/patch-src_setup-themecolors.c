--- src/setup-themecolors.c.orig	Wed Sep  1 23:53:45 2004
+++ src/setup-themecolors.c	Thu Sep  2 00:02:11 2004
@@ -33,133 +33,143 @@
   GtkWidget *cw;
   char hex[7];
   GString *glade_name;
+  GString *bg_normal, *bg_active, *bg_prelight, *bg_selected, *bg_insensitive;
+  GString *fg_normal, *fg_active, *fg_prelight, *fg_selected, *fg_insensitive;
+  GString *base_normal, *base_active, *base_prelight, *base_selected,
+	  *base_insensitive;
+  GString *text_normal, *text_active, *text_prelight, *text_selected,
+	  *text_insensitive;
+  GString *homedir;
+  GString *gtkrc20widget;
+  GtkWidget *w1;
+  gboolean b1;
 
   glade_name = g_string_append(g_string_new("bg[NORMAL]"), "_colorbutton");
   cw = glade_xml_get_widget (main_window_xml, glade_name->str);
   gtk_color_button_get_color(GTK_COLOR_BUTTON(cw), &color);
   sprintf(hex, "%02x%02x%02x", color.red/256, color.green/256, color.blue/256);
-  GString *bg_normal = g_string_prepend(g_string_new(hex), "#");
+  bg_normal = g_string_prepend(g_string_new(hex), "#");
   
   glade_name = g_string_append(g_string_new("bg[ACTIVE]"), "_colorbutton");
   cw = glade_xml_get_widget (main_window_xml, glade_name->str);
   gtk_color_button_get_color(GTK_COLOR_BUTTON(cw), &color);
   sprintf(hex, "%02x%02x%02x", color.red/256, color.green/256, color.blue/256);
-  GString *bg_active = g_string_prepend(g_string_new(hex), "#");
+  bg_active = g_string_prepend(g_string_new(hex), "#");
   
   glade_name = g_string_append(g_string_new("bg[PRELIGHT]"), "_colorbutton");
   cw = glade_xml_get_widget (main_window_xml, glade_name->str);
   gtk_color_button_get_color(GTK_COLOR_BUTTON(cw), &color);
   sprintf(hex, "%02x%02x%02x", color.red/256, color.green/256, color.blue/256);
-  GString *bg_prelight = g_string_prepend(g_string_new(hex), "#");
+  bg_prelight = g_string_prepend(g_string_new(hex), "#");
   
   glade_name = g_string_append(g_string_new("bg[SELECTED]"), "_colorbutton");
   cw = glade_xml_get_widget (main_window_xml, glade_name->str);
   gtk_color_button_get_color(GTK_COLOR_BUTTON(cw), &color);
   sprintf(hex, "%02x%02x%02x", color.red/256, color.green/256, color.blue/256);
-  GString *bg_selected = g_string_prepend(g_string_new(hex), "#");
+  bg_selected = g_string_prepend(g_string_new(hex), "#");
   
   glade_name = g_string_append(g_string_new("bg[INSENSITIVE]"), "_colorbutton");
   cw = glade_xml_get_widget (main_window_xml, glade_name->str);
   gtk_color_button_get_color(GTK_COLOR_BUTTON(cw), &color);
   sprintf(hex, "%02x%02x%02x", color.red/256, color.green/256, color.blue/256);
-  GString *bg_insensitive = g_string_prepend(g_string_new(hex), "#");
+  bg_insensitive = g_string_prepend(g_string_new(hex), "#");
   
 
   glade_name = g_string_append(g_string_new("fg[NORMAL]"), "_colorbutton");
   cw = glade_xml_get_widget (main_window_xml, glade_name->str);
   gtk_color_button_get_color(GTK_COLOR_BUTTON(cw), &color);
   sprintf(hex, "%02x%02x%02x", color.red/256, color.green/256, color.blue/256);
-  GString *fg_normal = g_string_prepend(g_string_new(hex), "#");
+  fg_normal = g_string_prepend(g_string_new(hex), "#");
   
   glade_name = g_string_append(g_string_new("fg[ACTIVE]"), "_colorbutton");
   cw = glade_xml_get_widget (main_window_xml, glade_name->str);
   gtk_color_button_get_color(GTK_COLOR_BUTTON(cw), &color);
   sprintf(hex, "%02x%02x%02x", color.red/256, color.green/256, color.blue/256);
-  GString *fg_active = g_string_prepend(g_string_new(hex), "#");
+  fg_active = g_string_prepend(g_string_new(hex), "#");
   
   glade_name = g_string_append(g_string_new("fg[PRELIGHT]"), "_colorbutton");
   cw = glade_xml_get_widget (main_window_xml, glade_name->str);
   gtk_color_button_get_color(GTK_COLOR_BUTTON(cw), &color);
   sprintf(hex, "%02x%02x%02x", color.red/256, color.green/256, color.blue/256);
-  GString *fg_prelight = g_string_prepend(g_string_new(hex), "#");
+  fg_prelight = g_string_prepend(g_string_new(hex), "#");
   
   glade_name = g_string_append(g_string_new("fg[SELECTED]"), "_colorbutton");
   cw = glade_xml_get_widget (main_window_xml, glade_name->str);
   gtk_color_button_get_color(GTK_COLOR_BUTTON(cw), &color);
   sprintf(hex, "%02x%02x%02x", color.red/256, color.green/256, color.blue/256);
-  GString *fg_selected = g_string_prepend(g_string_new(hex), "#");
+  fg_selected = g_string_prepend(g_string_new(hex), "#");
   
   glade_name = g_string_append(g_string_new("fg[INSENSITIVE]"), "_colorbutton");
   cw = glade_xml_get_widget (main_window_xml, glade_name->str);
   gtk_color_button_get_color(GTK_COLOR_BUTTON(cw), &color);
   sprintf(hex, "%02x%02x%02x", color.red/256, color.green/256, color.blue/256);
-  GString *fg_insensitive = g_string_prepend(g_string_new(hex), "#");
+  fg_insensitive = g_string_prepend(g_string_new(hex), "#");
   
 
   glade_name = g_string_append(g_string_new("base[NORMAL]"), "_colorbutton");
   cw = glade_xml_get_widget (main_window_xml, glade_name->str);
   gtk_color_button_get_color(GTK_COLOR_BUTTON(cw), &color);
   sprintf(hex, "%02x%02x%02x", color.red/256, color.green/256, color.blue/256);
-  GString *base_normal = g_string_prepend(g_string_new(hex), "#");
+  base_normal = g_string_prepend(g_string_new(hex), "#");
   
   glade_name = g_string_append(g_string_new("base[ACTIVE]"), "_colorbutton");
   cw = glade_xml_get_widget (main_window_xml, glade_name->str);
   gtk_color_button_get_color(GTK_COLOR_BUTTON(cw), &color);
   sprintf(hex, "%02x%02x%02x", color.red/256, color.green/256, color.blue/256);
-  GString *base_active = g_string_prepend(g_string_new(hex), "#");
+  base_active = g_string_prepend(g_string_new(hex), "#");
   
   glade_name = g_string_append(g_string_new("base[PRELIGHT]"), "_colorbutton");
   cw = glade_xml_get_widget (main_window_xml, glade_name->str);
   gtk_color_button_get_color(GTK_COLOR_BUTTON(cw), &color);
   sprintf(hex, "%02x%02x%02x", color.red/256, color.green/256, color.blue/256);
-  GString *base_prelight = g_string_prepend(g_string_new(hex), "#");
+  base_prelight = g_string_prepend(g_string_new(hex), "#");
   
   glade_name = g_string_append(g_string_new("base[SELECTED]"), "_colorbutton");
   cw = glade_xml_get_widget (main_window_xml, glade_name->str);
   gtk_color_button_get_color(GTK_COLOR_BUTTON(cw), &color);
   sprintf(hex, "%02x%02x%02x", color.red/256, color.green/256, color.blue/256);
-  GString *base_selected = g_string_prepend(g_string_new(hex), "#");
+  base_selected = g_string_prepend(g_string_new(hex), "#");
   
   glade_name = g_string_append(g_string_new("base[INSENSITIVE]"), "_colorbutton");
   cw = glade_xml_get_widget (main_window_xml, glade_name->str);
   gtk_color_button_get_color(GTK_COLOR_BUTTON(cw), &color);
   sprintf(hex, "%02x%02x%02x", color.red/256, color.green/256, color.blue/256);
-  GString *base_insensitive = g_string_prepend(g_string_new(hex), "#");
+  base_insensitive = g_string_prepend(g_string_new(hex), "#");
   
 
   glade_name = g_string_append(g_string_new("text[NORMAL]"), "_colorbutton");
   cw = glade_xml_get_widget (main_window_xml, glade_name->str);
   gtk_color_button_get_color(GTK_COLOR_BUTTON(cw), &color);
   sprintf(hex, "%02x%02x%02x", color.red/256, color.green/256, color.blue/256);
-  GString *text_normal = g_string_prepend(g_string_new(hex), "#");
+  text_normal = g_string_prepend(g_string_new(hex), "#");
   
   glade_name = g_string_append(g_string_new("text[ACTIVE]"), "_colorbutton");
   cw = glade_xml_get_widget (main_window_xml, glade_name->str);
   gtk_color_button_get_color(GTK_COLOR_BUTTON(cw), &color);
   sprintf(hex, "%02x%02x%02x", color.red/256, color.green/256, color.blue/256);
-  GString *text_active = g_string_prepend(g_string_new(hex), "#");
+  text_active = g_string_prepend(g_string_new(hex), "#");
   
   glade_name = g_string_append(g_string_new("text[PRELIGHT]"), "_colorbutton");
   cw = glade_xml_get_widget (main_window_xml, glade_name->str);
   gtk_color_button_get_color(GTK_COLOR_BUTTON(cw), &color);
   sprintf(hex, "%02x%02x%02x", color.red/256, color.green/256, color.blue/256);
-  GString *text_prelight = g_string_prepend(g_string_new(hex), "#");
+  text_prelight = g_string_prepend(g_string_new(hex), "#");
   
   glade_name = g_string_append(g_string_new("text[SELECTED]"), "_colorbutton");
   cw = glade_xml_get_widget (main_window_xml, glade_name->str);
   gtk_color_button_get_color(GTK_COLOR_BUTTON(cw), &color);
   sprintf(hex, "%02x%02x%02x", color.red/256, color.green/256, color.blue/256);
-  GString *text_selected = g_string_prepend(g_string_new(hex), "#");
+  text_selected = g_string_prepend(g_string_new(hex), "#");
   
   glade_name = g_string_append(g_string_new("text[INSENSITIVE]"), "_colorbutton");
   cw = glade_xml_get_widget (main_window_xml, glade_name->str);
   gtk_color_button_get_color(GTK_COLOR_BUTTON(cw), &color);
   sprintf(hex, "%02x%02x%02x", color.red/256, color.green/256, color.blue/256);
-  GString *text_insensitive = g_string_prepend(g_string_new(hex), "#");
+  text_insensitive = g_string_prepend(g_string_new(hex), "#");
 
   
-  GString *homedir = g_string_new(getenv("HOME"));
-  GString *gtkrc20widget = g_string_new(g_string_append(homedir, "/.gtkrc-2.0-widget_cog")->str);
+  homedir = g_string_new(getenv("HOME"));
+  gtkrc20widget = g_string_new(g_string_append(homedir, "/.gtkrc-2.0-widget_cog")->str);
 
   write_widget_gtkrc(gtkrc20widget->str,
 		     fg_normal->str, fg_active->str, fg_prelight->str, fg_selected->str, fg_insensitive->str,
@@ -167,8 +177,8 @@
 		     base_normal->str, base_active->str, base_prelight->str, base_selected->str, base_insensitive->str,
 		     text_normal->str, text_active->str, text_prelight->str, text_selected->str, text_insensitive->str);
 
-  GtkWidget *w1 = glade_xml_get_widget (main_window_xml, "enable_themecolors_checkbutton");
-  gboolean b1 = gtk_toggle_button_get_active (GTK_TOGGLE_BUTTON(w1));
+  w1 = glade_xml_get_widget (main_window_xml, "enable_themecolors_checkbutton");
+  b1 = gtk_toggle_button_get_active (GTK_TOGGLE_BUTTON(w1));
   if (b1)
     {
       gtkrc_apply_changes();
@@ -192,18 +202,21 @@
 {
   GtkWidget *w;
   GString *glade_name = g_string_append(g_string_new(name), "_colorbutton");
+  GdkColor color;
+  GString *homedir;
+  GString *gtkrc20widget;
+  char *parse_str;
   w = glade_xml_get_widget (main_window_xml, glade_name->str);
 
   g_signal_connect (G_OBJECT (w), "color-set",
   		    G_CALLBACK (color_set_callback),
   		    name);
-  /* Set correct initial value of widget */
-  GdkColor color;
 
-  GString *homedir = g_string_new(getenv("HOME"));
-  GString *gtkrc20widget = g_string_new(g_string_append(homedir, "/.gtkrc-2.0-widget_cog")->str);
+  /* Set correct initial value of widget */
+  homedir = g_string_new(getenv("HOME"));
+  gtkrc20widget = g_string_new(g_string_append(homedir, "/.gtkrc-2.0-widget_cog")->str);
 
-  char *parse_str = get_widget_color(gtkrc20widget->str, name);
+  parse_str = get_widget_color(gtkrc20widget->str, name);
   gdk_color_parse(parse_str, &color);
   gtk_color_button_set_color (GTK_COLOR_BUTTON(w), &color);
 }
