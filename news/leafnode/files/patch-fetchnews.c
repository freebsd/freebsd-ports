--- fetchnews.c	7 May 2004 08:34:15 -0000	1.173
+++ fetchnews.c	24 May 2004 13:23:22 -0000	1.174
@@ -1622,8 +1622,9 @@
 	freelist(groups);
     } else {
 	ln_log(LNLOG_SINFO, LNLOG_CSERVER,
-	    "%s: getting all newsgroups (debug: active: %p, forceactive: %s)",
-		current_server->name, (void *)active, forceactive ? "true" : "false");
+	    "%s: getting all newsgroups (debug: active: %s, forceactive: %s)",
+		current_server->name,
+		active ? "set" : "nil", forceactive ? "true" : "false");
 	xsnprintf(lineout, SIZE_lineout, "LIST\r\n");
 	putaline();
 	if (nntpreply(current_server) != 215) {
