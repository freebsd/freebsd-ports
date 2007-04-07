--- tools/hal-storage-mount.c.orig	Sun May 14 20:57:59 2006
+++ tools/hal-storage-mount.c	Sat Apr  7 12:50:53 2007
@@ -513,23 +513,11 @@
 	explicit_mount_point_given = FALSE;
 	if (strlen (mount_point) == 0) {
 		char *p;
-		const char *label;
+		char *basename;
 
-		if (volume != NULL)
-			label = libhal_volume_get_label (volume);
-		else
-			label = NULL;
-
-		if (label != NULL) {
-			/* best - use label */
-			g_strlcpy (mount_point, label, sizeof (mount_point));
-
-			/* TODO: use drive type */
-
-		} else {
-			/* fallback - use "disk" */
-			g_snprintf (mount_point, sizeof (mount_point), "disk");
-		}
+		basename = g_path_get_basename (device);
+		g_strlcpy (mount_point, basename, sizeof (mount_point));
+		g_free (basename);
 
 		/* sanitize computed mount point name, e.g. replace invalid chars with '-' */
 		p = mount_point;
