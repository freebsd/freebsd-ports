--- ./src/gst/parole-gst.c.orig	2013-03-07 00:14:28.000000000 +0000
+++ ./src/gst/parole-gst.c	2013-04-28 16:06:10.000000000 +0000
@@ -33,9 +33,11 @@
 #if GST_CHECK_VERSION(1, 0, 0)
 #include <gst/video/videooverlay.h>
 #include <gst/video/navigation.h>
+#include <gst/audio/streamvolume.h>
 #else
 #include <gst/interfaces/xoverlay.h>
 #include <gst/interfaces/navigation.h>
+#include <gst/interfaces/streamvolume.h>
 #endif
 
 #include <gst/pbutils/missing-plugins.h>
@@ -1573,22 +1575,36 @@
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
+                            GTK_RESPONSE_OK);
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
@@ -1712,7 +1728,7 @@
 #endif
 	             gst_install_plugins_context_free(ctx);
 	        }
-	        else if ( response == GTK_RESPONSE_REJECT )
+	        else if ( ( response == GTK_RESPONSE_REJECT ) || (response == GTK_RESPONSE_OK) )
 	            gtk_widget_destroy(GTK_WIDGET(dialog));
         }
 	    break;
@@ -2624,9 +2640,9 @@
 
 void parole_gst_set_volume (ParoleGst *gst, gdouble value)
 {
-    g_object_set (G_OBJECT (gst->priv->playbin),
-		  "volume", value,
-		  NULL);
+    gst_stream_volume_set_volume (GST_STREAM_VOLUME (gst->priv->playbin),
+				    GST_STREAM_VOLUME_FORMAT_CUBIC,
+				    value);
 }
 						    
 gdouble	parole_gst_get_volume (ParoleGst *gst)
