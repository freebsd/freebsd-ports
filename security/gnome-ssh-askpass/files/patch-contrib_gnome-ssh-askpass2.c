--- contrib/gnome-ssh-askpass2.c.orig	2020-02-14 00:40:54 UTC
+++ contrib/gnome-ssh-askpass2.c
@@ -90,13 +90,14 @@ passphrase_dialog(char *message, int prompt_type)
 {
 	const char *failed;
 	char *passphrase, *local;
-	int result, grab_tries, grab_server, grab_pointer;
+	int result, grab_tries, grab_server, grab_pointer, grab_keyboard;
 	int buttons, default_response;
 	GtkWidget *parent_window, *dialog, *entry;
 	GdkGrabStatus status;
 
 	grab_server = (getenv("GNOME_SSH_ASKPASS_GRAB_SERVER") != NULL);
 	grab_pointer = (getenv("GNOME_SSH_ASKPASS_GRAB_POINTER") != NULL);
+	grab_keyboard = (getenv("GNOME_SSH_ASKPASS_GRAB_KEYBOARD") != NULL);
 	grab_tries = 0;
 
 	/* Create an invisible parent window so that GtkDialog doesn't
@@ -156,18 +157,20 @@ passphrase_dialog(char *message, int prompt_type)
 			}
 		}
 	}
-	for(;;) {
-		status = gdk_keyboard_grab(
-		    gtk_widget_get_window(GTK_WIDGET(dialog)), FALSE,
-		    GDK_CURRENT_TIME);
-		if (status == GDK_GRAB_SUCCESS)
-			break;
-		usleep(GRAB_WAIT * 1000);
-		if (++grab_tries > GRAB_TRIES) {
-			failed = "keyboard";
-			goto nograbkb;
-		}
-	}
+    if (grab_keyboard) {
+	    for(;;) {
+		    status = gdk_keyboard_grab(
+		        gtk_widget_get_window(GTK_WIDGET(dialog)), FALSE,
+		        GDK_CURRENT_TIME);
+		    if (status == GDK_GRAB_SUCCESS)
+			    break;
+		    usleep(GRAB_WAIT * 1000);
+		    if (++grab_tries > GRAB_TRIES) {
+			    failed = "keyboard";
+			    goto nograbkb;
+		    }
+	    }
+    }
 	if (grab_server) {
 		gdk_x11_grab_server();
 	}
@@ -179,7 +182,8 @@ passphrase_dialog(char *message, int prompt_type)
 		XUngrabServer(gdk_x11_get_default_xdisplay());
 	if (grab_pointer)
 		gdk_pointer_ungrab(GDK_CURRENT_TIME);
-	gdk_keyboard_ungrab(GDK_CURRENT_TIME);
+	if (grab_keyboard)
+		gdk_keyboard_ungrab(GDK_CURRENT_TIME);
 	gdk_flush();
 
 	/* Report passphrase if user selected OK */
