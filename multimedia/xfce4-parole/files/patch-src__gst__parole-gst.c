--- ./src/gst/parole-gst.c.orig	2013-05-26 15:18:14.000000000 +0000
+++ ./src/gst/parole-gst.c	2013-06-03 20:41:34.000000000 +0000
@@ -1579,22 +1579,36 @@
     dialog = GTK_MESSAGE_DIALOG(gtk_message_dialog_new_with_markup(
                             NULL,
                             GTK_DIALOG_MODAL | GTK_DIALOG_DESTROY_WITH_PARENT,
+#if defined(__linux__)
                             GTK_MESSAGE_QUESTION,
+#elif defined(__FreeBSD__)
+                            GTK_MESSAGE_WARNING,
+#endif
                             GTK_BUTTONS_NONE,
                             "<b><big>%s</big></b>", 
                             _("Additional software is required.")
                             ));
                             
+#if defined(__linux__)
     gtk_dialog_add_buttons( GTK_DIALOG(dialog), 
                             _("Don't Install"),
                             GTK_RESPONSE_REJECT,
                             _("Install"), 
                             GTK_RESPONSE_ACCEPT,
                             NULL );
+#elif defined(__FreeBSD__)
+    gtk_dialog_add_button( GTK_DIALOG(dialog), 
+                            GTK_STOCK_OK,
+                            GTK_RESPONSE_ACCEPT);
+#endif
     
     gtk_message_dialog_format_secondary_markup(dialog,
+#if defined(__linux__)
                                              "Parole needs <b>%s</b> to play this file.\n"
                                              "It can be installed automatically.",
+#elif defined(__FreeBSD__)
+                                             "Parole needs <b>%s</b> to play this file.",
+#endif
                                              desc);
     
     return GTK_DIALOG(dialog);
@@ -1718,7 +1732,7 @@
 #endif
 	             gst_install_plugins_context_free(ctx);
 	        }
-	        else if ( response == GTK_RESPONSE_REJECT )
+	        else if ( (response == GTK_RESPONSE_REJECT) || (response == GTK_RESPONSE_OK) )
 	            gtk_widget_destroy(GTK_WIDGET(dialog));
         }
 	    break;
