--- src/nettool.c.orig	Wed Dec 22 07:07:36 2004
+++ src/nettool.c	Mon Dec 27 21:22:28 2004
@@ -21,6 +21,7 @@
 #include <gnome.h>
 #include <sys/types.h>
 #include <sys/socket.h>
+#include <netinet/in.h>
 #include <signal.h>
 #include <errno.h>
 #include <sys/wait.h>
@@ -361,6 +362,10 @@
 						 	len, NULL);
 			}
 
+			g_free (text);
+
+			return TRUE;
+
 		} else if (status == G_IO_STATUS_AGAIN) {
 			char buf[1];
 
@@ -372,12 +377,14 @@
 				}
 				g_string_append_c (netinfo->command_output, buf[0]);
 			}
+
+			g_free (text);
+
+			return TRUE;
 		} else if (status == G_IO_STATUS_EOF) {
-		} 
+		}
 
 		g_free (text);
-
-		return TRUE;
 	}
 
 	/* The condition is not G_IO_HUP | G_IO_ERR | G_IO_NVAL, so
