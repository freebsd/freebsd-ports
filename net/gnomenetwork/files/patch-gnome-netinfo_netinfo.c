--- gnome-netinfo/netinfo.c.orig	Mon Nov 24 18:29:43 2003
+++ gnome-netinfo/netinfo.c	Sun Dec  7 01:00:52 2003
@@ -20,6 +20,7 @@
 
 #include <gnome.h>
 #include <sys/types.h>
+#include <sys/socket.h>
 #include <signal.h>
 #include <errno.h>
 #include <sys/wait.h>
@@ -253,14 +254,16 @@
 	if (condition & G_IO_IN) {
 		g_io_channel_read_line (channel, &text, &len, NULL, NULL);
 
-		if (netinfo->process_line != NULL) {
-			(netinfo->process_line) ((gpointer) netinfo, text,
-						 len, NULL);
-		}
+		if (text != NULL) {
+			if (netinfo->process_line != NULL) {
+				(netinfo->process_line) ((gpointer) netinfo, text,
+						 	len, NULL);
+			}
 
-		g_free (text);
+			g_free (text);
 
-		return TRUE;
+			return TRUE;
+		}
 	}
 
 	/* The condition is not G_IO_HUP | G_IO_ERR | G_IO_NVAL, so
@@ -285,6 +288,7 @@
 	}
 	return FALSE;
 }
+
 
 void
 netinfo_stop_process_command (Netinfo * netinfo)
