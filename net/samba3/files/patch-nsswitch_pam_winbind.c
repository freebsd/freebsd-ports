--- nsswitch/pam_winbind.c.orig	Thu Sep 29 23:52:42 2005
+++ nsswitch/pam_winbind.c	Mon Jan  2 03:40:23 2006
@@ -86,7 +86,7 @@
 	struct pam_response *resp;
 	
 	pmsg[0] = &msg[0];
-	msg[0].msg = text;
+	msg[0].msg = CONST_DISCARD(char *, text);
 	msg[0].msg_style = type;
 	
 	resp = NULL;
@@ -359,7 +359,7 @@
 		if (comment != NULL) {
 			pmsg[0] = &msg[0];
 			msg[0].msg_style = PAM_TEXT_INFO;
-			msg[0].msg = comment;
+			msg[0].msg = CONST_DISCARD(char *, comment);
 			i = 1;
 		} else {
 			i = 0;
@@ -367,13 +367,13 @@
 
 		pmsg[i] = &msg[i];
 		msg[i].msg_style = PAM_PROMPT_ECHO_OFF;
-		msg[i++].msg = prompt1;
+		msg[i++].msg = CONST_DISCARD(char *, prompt1);
 		replies = 1;
 
 		if (prompt2 != NULL) {
 			pmsg[i] = &msg[i];
 			msg[i].msg_style = PAM_PROMPT_ECHO_OFF;
-			msg[i++].msg = prompt2;
+			msg[i++].msg = CONST_DISCARD(char *, prompt2);
 			++replies;
 		}
 		/* so call the conversation expecting i responses */
