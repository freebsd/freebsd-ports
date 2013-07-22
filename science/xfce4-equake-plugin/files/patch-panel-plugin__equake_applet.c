Avoid warning during compilation stage.

--- ./panel-plugin/equake_applet.c.orig	2013-07-20 00:56:31.000000000 +0000
+++ ./panel-plugin/equake_applet.c	2013-07-20 15:58:24.000000000 +0000
@@ -907,7 +907,7 @@
 static void display_about_dialog(XfcePanelPlugin *applet, struct Equake_Data *equakedata)
 {
   GtkWidget *about;
-  gchar *auth[]={AUTHOR, NULL};
+  const gchar *auth[]={AUTHOR, NULL};
 
   about=gtk_about_dialog_new();
   if(about!=NULL)
@@ -919,7 +919,7 @@
     gtk_about_dialog_set_license((GtkAboutDialog*)about,LICENSE);
     gtk_about_dialog_set_website((GtkAboutDialog*)about,WEBSITE);
     gtk_about_dialog_set_website_label((GtkAboutDialog*)about,WEBSITELABEL);
-    gtk_about_dialog_set_authors((GtkAboutDialog*)about, (gchar*)auth);
+    gtk_about_dialog_set_authors((GtkAboutDialog*)about, (const gchar**)auth);
 
     g_signal_connect_swapped(about, "response", G_CALLBACK (gtk_widget_destroy), about);
     gtk_widget_show_all((GtkWidget*)about);
