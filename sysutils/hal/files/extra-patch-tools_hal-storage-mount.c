--- tools/hal-storage-mount.c.orig	2008-01-03 21:10:54.000000000 -0500
+++ tools/hal-storage-mount.c	2008-01-04 09:29:10.000000000 -0500
@@ -583,23 +583,11 @@ handle_mount (LibHalContext *hal_ctx, 
 		explicit_mount_point_given = FALSE;
 		if (strlen (mount_point) == 0) {
 			char *p;
-			const char *label;
+			char *basename;
 			
-			if (volume != NULL)
-				label = libhal_volume_get_label (volume);
-			else
-				label = NULL;
-			
-			if (label != NULL) {
-				/* best - use label */
-				g_strlcpy (mount_point, label, sizeof (mount_point));
-				
-				/* TODO: use drive type */
-				
-			} else {
-				/* fallback - use "disk" */
-				g_snprintf (mount_point, sizeof (mount_point), "%s", "disk");
-			}
+			basename = g_path_get_basename (device);
+			g_strlcpy (mount_point, basename, sizeof (mount_point));
+			g_free (basename);
 			
 			/* sanitize computed mount point name, e.g. replace invalid chars with '-' */
 			p = mount_point;
