--- src/nettool.c.orig	Fri Jan  7 23:13:56 2005
+++ src/nettool.c	Mon Jan 24 21:03:48 2005
@@ -22,6 +22,7 @@
 #include <glib/gi18n.h>
 #include <sys/types.h>
 #include <sys/socket.h>
+#include <netinet/in.h>
 #include <signal.h>
 #include <errno.h>
 #include <sys/wait.h>
@@ -357,6 +358,10 @@
 						 	len, NULL);
 			}
 
+			g_free (text);
+
+			return TRUE;
+
 		} else if (status == G_IO_STATUS_AGAIN) {
 			char buf[1];
 
@@ -368,12 +373,13 @@
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
