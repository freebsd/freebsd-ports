--- src/ck-sysdeps-unix.c.orig	2026-04-17 08:41:44 UTC
+++ src/ck-sysdeps-unix.c
@@ -390,15 +390,15 @@ static gchar *
 
 /* Call g_free on string when done using it. [transfer: full] */
 static gchar *
-get_rundir (guint uid)
+get_rundir (struct passwd *pwent)
 {
         const gchar *base;
 
         TRACE ();
 
-        base = RUNDIR "/user";
+        base = RUNDIR "/xdg";
 
-        return g_strdup_printf ("%s/%d", base, uid);
+        return g_strdup_printf ("%s/%s", base, pwent->pw_name);
 }
 
 static gboolean
@@ -408,7 +408,7 @@ create_rundir_base (guint uid)
 
         TRACE ();
 
-        base = RUNDIR "/user";
+        base = RUNDIR "/xdg";
 
         /* Create the base directory that we will own. */
         if (g_mkdir_with_parents (base, S_IRWXU | S_IRGRP | S_IXGRP | S_IROTH | S_IXOTH) != 0) {
@@ -477,7 +477,7 @@ ck_generate_runtime_dir_for_user (guint uid)
                 return NULL;
         }
 
-        dest = get_rundir (uid);
+        dest = get_rundir (pwent);
 
         /* Ensure any files from the last session are removed */
         if (g_file_test (dest, G_FILE_TEST_EXISTS) == TRUE) {
@@ -512,10 +512,19 @@ ck_remove_runtime_dir_for_user (guint uid)
 ck_remove_runtime_dir_for_user (guint uid)
 {
         gchar        *dest;
+        struct passwd *pwent;
 
         TRACE ();
 
-        dest = get_rundir (uid);
+        errno = 0;
+        pwent = getpwuid (uid);
+        if (pwent == NULL) {
+                g_warning ("Unable to lookup UID: %s", g_strerror (errno));
+                errno = 0;
+                return FALSE;
+        }
+
+        dest = get_rundir (pwent);
 
         /* attempt to remove the tmpfs */
         ck_remove_tmpfs (uid, dest);
