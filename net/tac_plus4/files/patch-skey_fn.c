--- skey_fn.c.orig	2012-06-06 22:34:55.000000000 +0400
+++ skey_fn.c	2013-04-13 14:08:31.000000000 +0400
@@ -164,7 +164,7 @@
 		return(1);
 	    }
 
-	    if (skeychallenge(&p->skey, name, skeyprompt, 80) == 0) {
+	    if (skeychallenge(&p->skey, name, skeyprompt) == 0) {
 		char buf[256];
 		snprintf(buf, sizeof(buf), "%s\nS/Key challenge: ", skeyprompt);
 		data->server_msg = tac_strdup(buf);
