--- src/grg_prefs.h.orig	2008-09-01 16:06:36 UTC
+++ src/grg_prefs.h
@@ -24,15 +24,15 @@
 
 #include <gtk/gtk.h>
 
-gboolean grg_prefs_warn4overwrite;
-gboolean grg_prefs_bak_files;
-gboolean grg_prefs_splash;
-gboolean grg_prefs_tray;
-gboolean grg_prefs_clip_clear_on_close;
-gboolean grg_prefs_clip_clear_on_quit;
-gint grg_prefs_xpire;
-gint grg_prefs_wipe_passes;
-gint grg_prefs_mainwin_width, grg_prefs_mainwin_height;
+extern gboolean grg_prefs_warn4overwrite;
+extern gboolean grg_prefs_bak_files;
+extern gboolean grg_prefs_splash;
+extern gboolean grg_prefs_tray;
+extern gboolean grg_prefs_clip_clear_on_close;
+extern gboolean grg_prefs_clip_clear_on_quit;
+extern gint grg_prefs_xpire;
+extern gint grg_prefs_wipe_passes;
+extern gint grg_prefs_mainwin_width, grg_prefs_mainwin_height;
 
 gchar *get_pref_file (void);
 void set_pref_file (const gchar * newval);
