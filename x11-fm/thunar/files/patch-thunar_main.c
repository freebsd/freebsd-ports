Revert fix for bug #9513

--- thunar/main.c.orig	2015-05-15 16:38:08 UTC
+++ thunar/main.c
@@ -53,7 +53,7 @@ static gboolean opt_daemon = FALSE;
 static gchar   *opt_sm_client_id = NULL;
 static gboolean opt_quit = FALSE;
 static gboolean opt_version = FALSE;
-static ThunarFile *thunar_trash_file = NULL;
+
 
 
 /* --- command line options --- */
@@ -97,13 +97,6 @@ thunar_delayed_exit_check (gpointer user
     }
   else
     {
-      /* unref the trash bin */
-      if (thunar_trash_file != NULL)
-        {
-          g_object_unref (thunar_trash_file);
-          thunar_trash_file = NULL;
-        }
-
       /* no command line arguments opened in Thunar, exit now */
       gtk_main_quit ();
 
@@ -115,38 +108,6 @@ thunar_delayed_exit_check (gpointer user
 
 
 
-static void
-thunar_force_spawn_trash (void)
-{
-  GFile      *trash;
-
-  /* check that this has not happened yet */
-  if (thunar_trash_file != NULL)
-    return;
-
-  /* gvfs has no trash support */
-  if (!thunar_g_vfs_is_uri_scheme_supported ("trash"))
-    return;
-
-  trash = thunar_g_file_new_for_trash ();
-  thunar_trash_file = thunar_file_cache_lookup (trash);
-  if (thunar_trash_file == NULL)
-    {
-      thunar_trash_file = thunar_file_get (trash, NULL);
-      if (thunar_trash_file)
-        {
-          /* schedule a few reloads */
-          thunar_file_reload_idle (thunar_trash_file);
-          thunar_file_reload_idle_timeout (thunar_trash_file, 2000);
-          thunar_file_reload_idle_timeout (thunar_trash_file, 3000);
-          thunar_file_reload_idle_timeout (thunar_trash_file, 5000);
-        }
-    }
-  g_object_unref (trash);
-}
-
-
-
 int
 main (int argc, char **argv)
 {
@@ -290,14 +251,6 @@ main (int argc, char **argv)
   /* initialize the thunar stock items/icons */
   thunar_stock_init ();
 
-  /* For the trash state to be correct, gvfsd-trash needs to have been
-   * spawned. If the trash file is not in cache, this means we could
-   * access it the first time and the daemon might not have been
-   * spawned yet. So let's reload the trash later in idle, so that
-   * the state gets updated correctly (bug #9513).
-   */
-  thunar_force_spawn_trash ();
-
   /* acquire a reference on the global application */
   application = thunar_application_get ();
 
@@ -363,13 +316,6 @@ error0:
     g_object_unref (G_OBJECT (dbus_service));
 #endif
 
-  /* unreference the trash file */
-  if (thunar_trash_file != NULL)
-    {
-      g_object_unref (thunar_trash_file);
-      thunar_trash_file = NULL;
-    }
-
   /* disconnect from the session manager */
   g_object_unref (G_OBJECT (session_client));
 
