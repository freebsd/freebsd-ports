--- contrib/gnome-ssh-askpass2.c.orig	2016-12-19 04:59:41 UTC
+++ contrib/gnome-ssh-askpass2.c
@@ -86,12 +86,13 @@ passphrase_dialog(char *message)
 {
 	const char *failed;
 	char *passphrase, *local;
-	int result, grab_tries, grab_server, grab_pointer;
+	int result, grab_tries, grab_server, grab_pointer, grab_keyboard;
 	GtkWidget *parent_window, *dialog, *entry;
 	GdkGrabStatus status;
 
 	grab_server = (getenv("GNOME_SSH_ASKPASS_GRAB_SERVER") != NULL);
 	grab_pointer = (getenv("GNOME_SSH_ASKPASS_GRAB_POINTER") != NULL);
+    grab_keyboard = (getenv("GNOME_SSH_ASKPASS_GRAB_KEYBOARD") != NULL);
 	grab_tries = 0;
 
 	/* Create an invisible parent window so that GtkDialog doesn't
@@ -139,18 +140,20 @@ passphrase_dialog(char *message)
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
@@ -162,7 +165,8 @@ passphrase_dialog(char *message)
 		XUngrabServer(gdk_x11_get_default_xdisplay());
 	if (grab_pointer)
 		gdk_pointer_ungrab(GDK_CURRENT_TIME);
-	gdk_keyboard_ungrab(GDK_CURRENT_TIME);
+	if (grab_keyboard)
+		gdk_keyboard_ungrab(GDK_CURRENT_TIME);
 	gdk_flush();
 
 	/* Report passphrase if user selected OK */
@@ -178,13 +182,13 @@ passphrase_dialog(char *message)
 			puts(passphrase);
 		}
 	}
-		
+
 	/* Zero passphrase in memory */
 	memset(passphrase, '\b', strlen(passphrase));
 	gtk_entry_set_text(GTK_ENTRY(entry), passphrase);
 	memset(passphrase, '\0', strlen(passphrase));
 	g_free(passphrase);
-			
+
 	gtk_widget_destroy(dialog);
 	return (result == GTK_RESPONSE_OK ? 0 : -1);
 
@@ -197,7 +201,7 @@ passphrase_dialog(char *message)
 	if (grab_server)
 		XUngrabServer(gdk_x11_get_default_xdisplay());
 	gtk_widget_destroy(dialog);
-	
+
 	report_failed_grab(parent_window, failed);
 
 	return (-1);
