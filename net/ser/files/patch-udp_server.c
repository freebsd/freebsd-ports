
$FreeBSD$

--- udp_server.c
+++ udp_server.c
@@ -432,6 +432,10 @@
 				continue; /* goto skip;*/
 			else goto error;
 		}
+		if (len < 128) {
+			/* Message is too short, just drop it already */
+			continue;
+		}
 		/* we must 0-term the messages, receive_msg expects it */
 		buf[len]=0; /* no need to save the previous char */
 
