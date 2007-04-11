--- src/gnome-mount.c.orig	Sun Sep 17 01:17:54 2006
+++ src/gnome-mount.c	Sun Feb 11 01:03:16 2007
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
