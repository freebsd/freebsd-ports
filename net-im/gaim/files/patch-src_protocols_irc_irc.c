--- src/protocols/irc/irc.c.orig	Wed Mar 12 11:50:45 2003
+++ src/protocols/irc/irc.c	Wed Mar 12 12:20:56 2003
@@ -699,9 +699,11 @@
 
 	if ((c = irc_find_chat(gc, text))) {
 		char buf[IRC_BUF_LEN];
-		gaim_chat_set_topic(GAIM_CHAT(c), NULL, po);
+		char *utf8 = irc_recv_convert(gc, po);
+		gaim_chat_set_topic(GAIM_CHAT(c), NULL, utf8);
 		g_snprintf(buf, sizeof(buf), _("<B>%s has changed the topic to: %s</B>"),
-			   text, po);
+			   text, utf8);
+		g_free(utf8);
 
 		gaim_conversation_write(c, NULL, buf, -1, WFLAG_SYSTEM, time(NULL));
 	}
@@ -1616,12 +1618,14 @@
 {
 	struct gaim_conversation *c = irc_find_chat(gc, word[3]);
 	char *topic = *word_eol[4] == ':' ? word_eol[4] + 1 : word_eol[4];
-	char buf[IRC_BUF_LEN];
 
 	if (c) {
-		gaim_chat_set_topic(GAIM_CHAT(c), nick, topic);
+		char buf[IRC_BUF_LEN];
+		char *utf8 = irc_recv_convert(gc, topic);
+		gaim_chat_set_topic(GAIM_CHAT(c), nick, utf8);
 		g_snprintf(buf, sizeof(buf),
-				   _("<B>%s has changed the topic to: %s</B>"), nick, topic);
+				   _("<B>%s has changed the topic to: %s</B>"), nick, utf8);
+		g_free(utf8);
 
 		gaim_conversation_write(c, NULL, buf, -1, WFLAG_SYSTEM, time(NULL));
 	}

