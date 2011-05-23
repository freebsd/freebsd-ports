--- plugins/growisofs/burn-growisofs.c.orig	2011-05-23 20:22:46.000000000 +0700
+++ plugins/growisofs/burn-growisofs.c	2011-05-23 20:23:15.000000000 +0700
@@ -502,18 +502,18 @@
 			/* FIXME: is it right to mess with it ? 
 			   g_ptr_array_add (argv, g_strdup_printf ("-use-the-force-luke=bufsize:%im", 32)); */
 
-			if (!g_file_test ("/proc/self/fd/0", G_FILE_TEST_EXISTS)) {
+			if (!g_file_test ("/dev/fd/0", G_FILE_TEST_EXISTS)) {
 				g_set_error (error,
 					     BRASERO_BURN_ERROR,
 					     BRASERO_BURN_ERROR_FILE_NOT_FOUND,
 					     _("\"%s\" could not be found"),
-					     "/proc/self/fd/0");
+					     "/dev/fd/0");
 				return BRASERO_BURN_ERR;
 			}
 
 			/* FIXME: should we use DAO ? */
 			g_ptr_array_add (argv, g_strdup ("-Z"));
-			g_ptr_array_add (argv, g_strdup_printf ("%s=/proc/self/fd/0", device));
+			g_ptr_array_add (argv, g_strdup_printf ("%s=/dev/fd/0", device));
 			g_free (device);
 		}
 		else if (BRASERO_IS_TRACK_IMAGE (current)) {
