
$FreeBSD$

--- udp_server.c.orig	Sat Jun 21 21:38:32 2003
+++ udp_server.c	Sun Jul  6 20:53:30 2003
@@ -326,6 +326,10 @@
 				continue; /* goto skip;*/
 			else goto error;
 		}
+		if (len < 8) {
+			/* Message is too short, just drop it already */
+			continue;
+		}
 		/* we must 0-term the messages, receive_msg expects it */
 		buf[len]=0; /* no need to save the previous char */
 
