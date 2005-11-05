--- src/gnome-keyring-manager-util.c.orig	Wed May 18 16:41:35 2005
+++ src/gnome-keyring-manager-util.c	Sat Jul  2 02:12:38 2005
@@ -304,8 +304,6 @@ gkm_about_dialog_new (GtkWindow *transie
 {
   GtkWidget *about;
 
-  g_return_val_if_fail (GTK_IS_WINDOW (transient_parent), NULL);
-
   const char *authors[] = {
     "Fernando Herrera <fherrera@onirica.com>",
     "Mariano Su\303\241rez-Alvarez <mariano@gnome.org>",
@@ -317,6 +315,8 @@ gkm_about_dialog_new (GtkWindow *transie
     NULL
   };
 
+  g_return_val_if_fail (GTK_IS_WINDOW (transient_parent), NULL);
+
   gtk_about_dialog_set_email_hook ((GtkAboutDialogActivateLinkFunc) gkm_about_dialog_activate_links,
 				   GINT_TO_POINTER (LINK_TYPE_EMAIL), NULL);
 
@@ -354,6 +354,10 @@ gkm_get_application_path (void)
  	{
 	  path = g_file_read_link ("/proc/self/exe", NULL);
 	}     
+#elif defined(__FreeBSD__)
+	{
+	  path = g_file_read_link ("/proc/curproc/file", NULL);
+	}
 #endif
     }
 
