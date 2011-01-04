diff --git a/lib/misc.c b/lib/misc.c
index 91361e0..4aac9e3 100644
--- lib/misc.c
+++ lib/misc.c
@@ -411,7 +411,7 @@ create_containing_directory(gchar *name, gint dir_uid, gint dir_gid, gint dir_mo
         }
       else if (errno == ENOENT) 
         {
-          if (mkdir(name, (mode_t) dir_mode) == -1)
+          if (mkdir(name, dir_mode < 0 ? 0700 : (mode_t) dir_mode) == -1)
             return FALSE;
           saved_caps = g_process_cap_save();
           g_process_cap_modify(CAP_CHOWN, TRUE);
