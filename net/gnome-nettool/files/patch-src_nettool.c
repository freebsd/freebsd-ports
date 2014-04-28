--- src/nettool.c.orig	2009-06-18 13:51:14.000000000 -0400
+++ src/nettool.c	2009-07-19 16:05:59.000000000 -0400
@@ -24,6 +24,7 @@
 #include <string.h>
 #include <sys/types.h>
 #include <sys/socket.h>
+#include <netinet/in.h>
 #include <signal.h>
 #include <errno.h>
 #include <sys/wait.h>
@@ -374,6 +375,10 @@ netinfo_io_text_buffer_dialog (GIOChanne
 						 	len, NULL);
 			}
 
+			g_free (text);
+
+			return TRUE;
+
 		} else if (status == G_IO_STATUS_AGAIN) {
 			char buf[1];
 
@@ -385,6 +390,8 @@ netinfo_io_text_buffer_dialog (GIOChanne
 				}
 				g_string_append_c (netinfo->command_output, buf[0]);
 			}
+			g_free (text);
+			return TRUE;
 		} else if (status == G_IO_STATUS_EOF) {
 			
 		} else if (status == G_IO_STATUS_ERROR) {
@@ -402,15 +409,15 @@ netinfo_io_text_buffer_dialog (GIOChanne
 
 			} else {
 				g_warning ("Error: %s\n", err->message);
-				g_free (text);
 				g_free (err);
 			}
 
+			g_free (text);
+			return TRUE;
+
 		}
 
 		g_free (text);
-
-		return TRUE;
 	}
 
 	/* The condition is not G_IO_HUP | G_IO_ERR | G_IO_NVAL, so
