--- tools/hal-storage-mount.c.orig	2008-05-20 13:24:30.000000000 -0400
+++ tools/hal-storage-mount.c	2008-05-20 13:30:14.000000000 -0400
@@ -585,17 +585,11 @@ handle_mount (LibHalContext *hal_ctx, 
 		explicit_mount_point_given = FALSE;
 		if (strlen (mount_point) == 0) {
 			char *p;
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
+			char *basename;
+
+			basename = g_path_get_basename (device);
+			g_strlcpy (mount_point, basename, sizeof (mount_point));
+			g_free (basename);
 			
 			/* sanitize computed mount point name, e.g. replace invalid chars with '-' */
 			p = mount_point;
