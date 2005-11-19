--- gtk/gtkiconcache.c.orig	Mon Aug 29 07:05:13 2005
+++ gtk/gtkiconcache.c	Sat Nov 19 19:14:10 2005
@@ -75,6 +75,37 @@
     }
 }
 
+static gboolean
+is_uptodate (const char *dirname, time_t cache_mtime)
+{
+  GDir *dir;
+  const char *filename;
+  gboolean uptodate = TRUE;
+
+  dir = g_dir_open (dirname, 0, NULL);
+  if (! dir)
+    return TRUE;
+
+  while (uptodate && (filename = g_dir_read_name (dir)))
+    if (filename[0] != '.')
+      {
+	char *pathname;
+	struct stat st;
+
+	pathname = g_build_filename (dirname, filename, NULL);
+	if (g_stat (pathname, &st) >= 0
+	    && (cache_mtime < st.st_mtime
+		|| (S_ISDIR (st.st_mode)
+		    && ! is_uptodate (pathname, cache_mtime))))
+	    uptodate = FALSE;
+	g_free(pathname);
+      }
+
+  g_dir_close(dir);
+
+  return uptodate;
+}
+
 GtkIconCache *
 _gtk_icon_cache_new_for_path (const gchar *path)
 {
@@ -106,7 +137,7 @@
     goto done;
 
   /* Verify cache is uptodate */
-  if (st.st_mtime < path_st.st_mtime)
+  if (st.st_mtime < path_st.st_mtime || ! is_uptodate(path, st.st_mtime))
     {
       GTK_NOTE (ICONTHEME, 
 		g_print ("cache outdated\n"));
