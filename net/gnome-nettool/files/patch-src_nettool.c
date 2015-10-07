--- src/nettool.c.orig	2012-01-03 10:38:09.000000000 +0100
+++ src/nettool.c	2015-08-28 16:28:52.904785000 +0200
@@ -28,7 +28,6 @@
 #include <string.h>
 #include <sys/types.h>
 #include <sys/socket.h>
-#include <netinet/in.h>
 #include <signal.h>
 #include <errno.h>
 #include <sys/wait.h>
@@ -410,6 +409,10 @@ netinfo_io_text_buffer_dialog (GIOChanne
 						 	len, NULL);
 			}
 
+			g_free (text);
+
+			return TRUE;
+
 		} else if (status == G_IO_STATUS_AGAIN) {
 			char buf[1];
 
@@ -421,6 +424,11 @@ netinfo_io_text_buffer_dialog (GIOChanne
 				}
 				g_string_append_c (netinfo->command_output, buf[0]);
 			}
+
+			g_free (text);
+
+			return TRUE;
+
 		} else if (status == G_IO_STATUS_EOF) {
 			
 		} else if (status == G_IO_STATUS_ERROR) {
@@ -438,15 +446,16 @@ netinfo_io_text_buffer_dialog (GIOChanne
 
 			} else {
 				g_warning ("Error: %s\n", err->message);
-				g_free (text);
 				g_free (err);
 			}
 
-		}
-
 		g_free (text);
 
 		return TRUE;
+
+		}
+
+		g_free (text);
 	}
 
 	/* The condition is not G_IO_HUP | G_IO_ERR | G_IO_NVAL, so
