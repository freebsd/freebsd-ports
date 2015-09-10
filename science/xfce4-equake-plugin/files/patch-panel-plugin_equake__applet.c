--- panel-plugin/equake_applet.c.orig	2015-08-18 21:05:07 UTC
+++ panel-plugin/equake_applet.c
@@ -887,7 +887,7 @@ static void set_properties_from_dialog(i
 static void display_about_dialog(XfcePanelPlugin *applet, struct Equake_Data *equakedata)
 {
   GtkWidget *about;
-  gchar *auth[]={AUTHOR, NULL};
+  const gchar *auth[]={AUTHOR, NULL};
 
   about=gtk_about_dialog_new();
   if(about!=NULL)
@@ -899,7 +899,7 @@ static void display_about_dialog(XfcePan
     gtk_about_dialog_set_license((GtkAboutDialog*)about,LICENSE);
     gtk_about_dialog_set_website((GtkAboutDialog*)about,WEBSITE);
     gtk_about_dialog_set_website_label((GtkAboutDialog*)about,WEBSITELABEL);
-    gtk_about_dialog_set_authors((GtkAboutDialog*)about, (gchar*)auth);
+    gtk_about_dialog_set_authors((GtkAboutDialog*)about, (const gchar**)auth);
 
     g_signal_connect_swapped(about, "response", G_CALLBACK (gtk_widget_destroy), about);
     gtk_widget_show_all((GtkWidget*)about);
