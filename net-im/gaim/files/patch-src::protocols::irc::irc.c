--- src/protocols/irc/irc.c.orig	Thu Jul 17 22:55:23 2003
+++ src/protocols/irc/irc.c	Wed Aug 13 08:30:08 2003
@@ -1153,7 +1153,9 @@
 			if (*who == '+')
 				who++;
 			if (!gaim_utf8_strcasecmp(who, nick)) {
-				gaim_chat_remove_user(chat, who, reason);
+				char *tmp = g_strdup(r->data);
+				gaim_chat_remove_user(chat, tmp, reason);
+				g_free(tmp);
 				break;
 			}
 			r = r->next;
@@ -1793,7 +1795,9 @@
 		if (*who == '+')
 			who++;
 		if (!gaim_utf8_strcasecmp(who, nick)) {
-			gaim_chat_remove_user(chat, who, reason);
+			char *tmp = g_strdup(r->data);
+			gaim_chat_remove_user(chat, tmp, reason);
+			g_free(tmp);
 			break;
 		}
 		r = r->next;
