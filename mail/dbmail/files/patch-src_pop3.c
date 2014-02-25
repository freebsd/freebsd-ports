diff --git src/pop3.c src/pop3.c
index 2b8792e..a09524e 100644
--- src/pop3.c
+++ src/pop3.c
@@ -302,7 +302,6 @@ int pop3_error(ClientSession_T * session, const char *formatstring, ...)
 
 	if (session->error_count >= MAX_ERRORS) {
 		ci_write(ci, "-ERR too many errors\r\n");
-		client_session_bailout(&session);
 		return -3;
 	} 
 	va_start(ap, formatstring);
@@ -314,7 +313,6 @@ int pop3_error(ClientSession_T * session, const char *formatstring, ...)
 	g_free(s);
 
 	if (ci->client_state & CLIENT_ERR) {
-		client_session_bailout(&session);
 		return -3;
 	}
 
