--- src/nettool.c.orig	Tue May 10 18:14:48 2005
+++ src/nettool.c	Sun Apr 23 22:00:13 2006
@@ -24,6 +24,7 @@
 #include <string.h>
 #include <sys/types.h>
 #include <sys/socket.h>
+#include <netinet/in.h>
 #include <signal.h>
 #include <errno.h>
 #include <sys/wait.h>
@@ -315,7 +316,7 @@ netinfo_io_text_buffer_dialog (GIOChanne
 			       GIOCondition condition, gpointer data)
 {
 	gchar *text = NULL;
-	gint len;
+	gsize len;
 	Netinfo *netinfo = (Netinfo *) data;
 
 	g_return_val_if_fail (channel != NULL, FALSE);
@@ -360,6 +361,10 @@ netinfo_io_text_buffer_dialog (GIOChanne
 						 	len, NULL);
 			}
 
+			g_free (text);
+
+			return TRUE;
+
 		} else if (status == G_IO_STATUS_AGAIN) {
 			char buf[1];
 
@@ -371,12 +376,13 @@ netinfo_io_text_buffer_dialog (GIOChanne
 				}
 				g_string_append_c (netinfo->command_output, buf[0]);
 			}
+
+			g_free (text);
+			return TRUE;
 		} else if (status == G_IO_STATUS_EOF) {
 		}
 
 		g_free (text);
-
-		return TRUE;
 	}
 
 	/* The condition is not G_IO_HUP | G_IO_ERR | G_IO_NVAL, so
