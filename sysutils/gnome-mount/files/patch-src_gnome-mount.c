--- src/gnome-mount.c.orig	Sun Sep 17 01:17:54 2006
+++ src/gnome-mount.c	Sun Feb 11 01:03:16 2007
@@ -51,9 +51,14 @@
 #include <libhal.h>
 #include <libhal-storage.h>
 
-#ifndef sun
+#if !defined(sun) && !defined(__FreeBSD__)
 #include <mntent.h>
-#else
+#elif defined(__FreeBSD__)
+#include <fstab.h>
+#include <sys/param.h>
+#include <sys/ucred.h>
+#include <sys/mount.h>
+#elif defined(sun)
 #include <sys/mnttab.h>
 #endif
 
@@ -380,7 +385,7 @@ show_error_dialog_mount (LibHalVolume *v
 		} else if (strcmp (error_name, "org.freedesktop.Hal.Device.Volume.AlreadyMounted") == 0) {
 
 			/* don't show any dialog for this */
-			gtk_widget_unref (w);
+			gtk_widget_destroy (w);
 			w = NULL;
 
 #if 0
@@ -399,7 +404,7 @@ show_error_dialog_mount (LibHalVolume *v
 			 *
 			 * Don't show any dialog for this.
 			 */
-			gtk_widget_unref (w);
+			gtk_widget_destroy (w);
 			w = NULL;
 			 
 		} else {
@@ -582,19 +587,24 @@ static char *
 get_mntent_mount_point(const char *device_file)
 {
 	char *mount_point;
+#if! defined(sun) && !defined(__FreeBSD__)
 	FILE *f;
-#ifndef sun
 	struct mntent mnt;
 	struct mntent *mnte;
 	char buf[512];
-#else
+#elif defined(__FreeBSD__)
+	struct statfs *mounts;
+	int n_mounts;
+	int i;
+#elif defined(sun)
+	FILE *f;
 	struct mnttab mnt;
 	struct mnttab mpref = { NULL, NULL, NULL, NULL, NULL };
 #endif
 
 	mount_point = NULL;
 
-#ifndef sun
+#if !defined(sun) && !defined(__FreeBSD__)
 	if ((f = setmntent ("/proc/mounts", "r")) != NULL) {
 		
 		while ((mnte = getmntent_r (f, &mnt, buf, sizeof(buf))) != NULL) {
@@ -608,7 +618,7 @@ get_mntent_mount_point(const char *devic
 		endmntent (f);
 	}
 
-#else /* sun */
+#elif defined(sun) /* sun */
 
 	if ((f = fopen(MNTTAB, "r")) != NULL) {
 		mpref.mnt_special = (char *)device_file;
@@ -617,8 +627,13 @@ get_mntent_mount_point(const char *devic
 		}
 		fclose(f);
 	}
-
-#endif /* sun */
+#elif defined(__FreeBSD__)
+	n_mounts = getmntinfo(&mounts, MNT_NOWAIT);
+	for (i = 0; i < n_mounts; i++) {
+		if (!strcmp(mounts[i].f_mntfromname, device_file))
+			mount_point = g_strdup (mounts[i].f_mntonname);
+	}
+#endif /* sun && __FreeBSD__ */
 
 out:
 	return (mount_point);
@@ -1322,7 +1337,11 @@ volume_mount (const char *udi, LibHalVol
 	if (volume == NULL && (mount_options->len == 0)) {
 		/* volume from a non-pollable drive, just set uid.. */
 		
+#ifndef __FreeBSD__
 		snprintf (uidbuf, sizeof (uidbuf) - 1, "uid=%u", getuid ());
+#else
+		snprintf (uidbuf, sizeof (uidbuf) - 1, "-u=%u", getuid ());
+#endif
 		g_ptr_array_add (mount_options, uidbuf);
 		
 	} else if (((fstype_override != NULL) || (fstype != NULL)) && (mount_options->len == 0)) {
@@ -1349,9 +1368,15 @@ volume_mount (const char *udi, LibHalVol
 				g_debug ("read default option '%s' from gconf strlist key %s", option, key);
 
 				/* special workaround to replace "uid=" with "uid=<actual uid of caller>" */
+#ifndef __FreeBSD__
 				if (strcmp (option, "uid=") == 0) {
 					g_free (option);
 					option = g_strdup_printf ("uid=%u", getuid ());
+#else
+				if (strcmp (option, "-u=") == 0) {
+					g_free (option);
+					option = g_strdup_printf ("-u=%u", getuid ());
+#endif
 				}
 				g_ptr_array_add (mount_options, option);
 
