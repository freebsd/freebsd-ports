--- src/setup-gnomeui.c.orig	Wed Sep  1 23:12:01 2004
+++ src/setup-gnomeui.c	Wed Sep  1 23:52:18 2004
@@ -49,6 +49,9 @@
 {
   GtkWidget *w;
   gchar *gconf_key;
+  GString *homedir;
+  GString *gtkrc20;
+  GString *gtkrc20scrollbar;
 
   gconf_key = "/desktop/gnome/interface/menubar_detachable";
   w = glade_xml_get_widget (main_window_xml, "menubars_detach_checkbutton");
@@ -121,10 +124,10 @@
     }
 
 
-  GString *homedir = g_string_new(getenv("HOME"));
-  GString *gtkrc20 = g_string_new(g_string_append(homedir, "/.gtkrc-2.0")->str);
   homedir = g_string_new(getenv("HOME"));
-  GString *gtkrc20scrollbar = g_string_new(g_string_append(homedir, "/.gtkrc-2.0-scrollbar_cog")->str);
+  gtkrc20 = g_string_new(g_string_append(homedir, "/.gtkrc-2.0")->str);
+  homedir = g_string_new(getenv("HOME"));
+  gtkrc20scrollbar = g_string_new(g_string_append(homedir, "/.gtkrc-2.0-scrollbar_cog")->str);
 
   modify_gtkrc(gtkrc20->str, get_enable_colors(gtkrc20->str));
 
