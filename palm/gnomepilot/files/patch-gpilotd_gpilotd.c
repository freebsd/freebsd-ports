--- gpilotd/gpilotd.c.orig	Tue Sep 17 13:37:40 2002
+++ gpilotd/gpilotd.c	Tue Sep 17 13:38:32 2002
@@ -46,6 +46,7 @@
 #include <signal.h>
 #include <unistd.h>
 #include <stdio.h>
+#include <fcntl.h>
 
 #include <libgnome/libgnome.h>
 
@@ -125,13 +126,13 @@
 		pilot_set_baud_rate (device);
 	}
 
-	if (!(sd = pi_socket (PI_AF_SLP, PI_SOCK_STREAM, PI_PF_PADP))) {
+	if (!(sd = pi_socket (PI_PF_SLP, PI_SOCK_STREAM, PI_PF_PADP))) {
 		g_warning ("pi_socket: %s",strerror (errno));
 		if (error) *error = 1;
 		return -1;
 	}
 	
-	addr.pi_family = PI_AF_SLP;
+	addr.pi_family = PI_PF_SLP;
 
 /*
 	Most important for networking
