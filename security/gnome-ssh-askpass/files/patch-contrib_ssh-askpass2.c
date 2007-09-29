--- contrib/gnome-ssh-askpass2.c.orig  Tue Sep 19 09:58:45 2006
+++ contrib/gnome-ssh-askpass2.c       Tue Sep 19 10:03:27 2006
@@ -88,12 +88,13 @@
 {
 	const char *failed;
 	char *passphrase, *local;
-	int result, grab_tries, grab_server, grab_pointer;
+	int result, grab_tries, grab_server, grab_pointer, grab_keyboard;
 	GtkWidget *dialog, *entry;
 	GdkGrabStatus status;
 
 	grab_server = (getenv("GNOME_SSH_ASKPASS_GRAB_SERVER") != NULL);
 	grab_pointer = (getenv("GNOME_SSH_ASKPASS_GRAB_POINTER") != NULL);
+	grab_keyboard = (getenv("GNOME_SSH_ASKPASS_GRAB_KEYBOARD") != NULL);
 	grab_tries = 0;
 
 	dialog = gtk_message_dialog_new(NULL, 0,
@@ -135,17 +136,21 @@
 			}
 		}
 	}
-	for(;;) {
-		status = gdk_keyboard_grab((GTK_WIDGET(dialog))->window,
-		   FALSE, GDK_CURRENT_TIME);
-		if (status == GDK_GRAB_SUCCESS)
-			break;
-		usleep(GRAB_WAIT * 1000);
-		if (++grab_tries > GRAB_TRIES) {
-			failed = "keyboard";
-			goto nograbkb;
+
+	if (grab_keyboard) {
+		for(;;) {
+			status = gdk_keyboard_grab((GTK_WIDGET(dialog))->window,
+			   FALSE, GDK_CURRENT_TIME);
+			if (status == GDK_GRAB_SUCCESS)
+				break;
+			usleep(GRAB_WAIT * 1000);
+			if (++grab_tries > GRAB_TRIES) {
+				failed = "keyboard";
+				goto nograbkb;
+			}
 		}
 	}
+
 	if (grab_server) {
 		gdk_x11_grab_server();
 	}
@@ -157,7 +162,8 @@
 		XUngrabServer(GDK_DISPLAY());
 	if (grab_pointer)
 		gdk_pointer_ungrab(GDK_CURRENT_TIME);
-	gdk_keyboard_ungrab(GDK_CURRENT_TIME);
+	if (grab_keyboard)
+		gdk_keyboard_ungrab(GDK_CURRENT_TIME);
 	gdk_flush();
 
 	/* Report passphrase if user selected OK */
