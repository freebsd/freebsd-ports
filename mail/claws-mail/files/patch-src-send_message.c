Index: src/send_message.c
===================================================================
RCS file: /cvsroot/sylpheed-claws/sylpheed-claws/src/send_message.c,v
retrieving revision 1.17.2.9
retrieving revision 1.17.2.10
diff -u -r1.17.2.9 -r1.17.2.10
--- src/send_message.c	30 Apr 2005 16:47:40 -0000	1.17.2.9
+++ src/send_message.c	20 May 2005 16:24:12 -0000	1.17.2.10
@@ -333,7 +333,8 @@
 	 * easier.
 	 */
 	if (!keep_session || ret != 0) {
-		smtp_quit(session);
+		if (session_is_connected(session))
+			smtp_quit(session);
 		while (session_is_connected(session))
 			gtk_main_iteration();
 		session_destroy(session);


