--- src/protocols/silc/chat.c.orig	Wed Jun  2 14:36:55 2004
+++ src/protocols/silc/chat.c	Wed Jun  2 14:37:03 2004
@@ -1081,7 +1081,7 @@
 	   do both 1 and 2 with default keys. */
 
 	/* Call JOIN */
-	if (passphrase)
+	if (passphrase && strlen(passphrase))
 		silc_client_command_call(client, conn, NULL, "JOIN",
 					 channel, passphrase, "-auth", "-founder", NULL);
 	else
