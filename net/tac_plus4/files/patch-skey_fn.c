--- skey_fn.c.orig	Sun Apr  3 01:41:00 2005
+++ skey_fn.c	Sun Apr  3 01:41:08 2005
@@ -168,7 +168,7 @@
 		return(1);
 	    }
 
-	    if (skeychallenge(&p->skey, name, skeyprompt, 80) == 0) {
+	    if (skeychallenge(&p->skey, name, skeyprompt) == 0) {
 		char buf[256];
 		sprintf(buf, "%s\nPassword: ", skeyprompt);
 		data->server_msg = tac_strdup(buf);
