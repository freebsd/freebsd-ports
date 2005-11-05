--- nautilus-cd-burner.c.orig	Wed May 11 18:56:59 2005
+++ nautilus-cd-burner.c	Tue May 17 17:11:49 2005
@@ -25,6 +25,8 @@
  *          William Jon McCann <mccann@jhu.edu>
  */
 
+#include <sys/types.h>
+#include <sys/stat.h>
 #include <time.h>
 #include <stdio.h>
 #include <stdlib.h>
@@ -1103,10 +1105,20 @@ burn_cd (const NautilusBurnDrive *drive,
 		}
 
 		if (res == NAUTILUS_BURN_RECORDER_RESULT_RETRY) {
+			gchar *path1;
+
+			path1 = g_strdup_printf ("%s/.ncb", g_get_home_dir());
+
+			if (!g_file_test (path1, G_FILE_TEST_EXISTS)) {
+				mkdir (path1, 0700);
+			}
+
 			g_free (toc_filename);
 			g_free (filename);
 
-			filename = g_build_filename (g_get_tmp_dir (), "image.iso.XXXXXX", NULL);
+			filename = g_build_filename (path1, "image.iso.XXXXXX", NULL);
+			g_free (path1);
+
 			fd = g_mkstemp (filename);
 			close (fd);
 
