--- src/connect.c.orig	Mon May  1 03:33:13 2006
+++ src/connect.c	Mon May  1 03:33:26 2006
@@ -1288,7 +1288,7 @@ on_btnConnect_clicked                  (
   GtkWidget *main_window;
   rdp_file *rdp = NULL;
   gchar *home = tsc_home_path ();
-  gchar *filename = g_build_path ("/", home, "last.tsc");
+  gchar *filename = g_build_path ("/", home, "last.tsc", NULL);
 
   #ifdef TSCLIENT_DEBUG
   printf ("on_btnConnect_clicked\n");
@@ -1325,7 +1325,7 @@ on_btnQuit_clicked                     (
   GtkWidget *main_window;
   rdp_file *rdp_last = NULL;
   gchar *home = tsc_home_path ();
-  gchar *filename = g_build_path ("/", home, "last.tsc");
+  gchar *filename = g_build_path ("/", home, "last.tsc", NULL);
 
   #ifdef TSCLIENT_DEBUG
   printf ("on_btnQuit_clicked\n");
