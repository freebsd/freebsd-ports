--- nautilus-cd-burner.c.orig	Sun Sep 19 18:44:15 2004
+++ nautilus-cd-burner.c	Sun Oct 31 13:06:08 2004
@@ -21,6 +21,8 @@
   
    Authors: Alexander Larsson <alexl@redhat.com>
 */
+#include <sys/types.h>
+#include <sys/stat.h>
 #include <gtk/gtk.h>
 #include <gtk/gtkfilesel.h>
 #include <gtk/gtkseparatormenuitem.h>
@@ -632,8 +634,19 @@
 		}
 
 		if (res == RESULT_RETRY) {
-			g_free (filename);
-			filename = g_build_filename (g_get_tmp_dir (), "image.iso.XXXXXX", NULL);
+			gchar *path1;
+
+			path1 = g_strdup_printf ("%s/.ncb", g_get_home_dir());
+
+			if (!g_file_test (path1, G_FILE_TEST_EXISTS)) {
+				mkdir (path1, 0700);
+			}
+
+			if (filename != NULL) {
+				g_free (filename);
+			}
+			filename = g_build_filename (path1, "image.iso.XXXXXX", NULL);
+			g_free (path1);
 			fd = g_mkstemp(filename);
 			close (fd);
 
