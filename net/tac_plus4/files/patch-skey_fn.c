--- skey_fn.c.orig	2012-06-06 18:34:55 UTC
+++ skey_fn.c
@@ -164,7 +164,7 @@ skey_fn(struct authen_data *data)
 		return(1);
 	    }
 
-	    if (skeychallenge(&p->skey, name, skeyprompt, 80) == 0) {
+	    if (skeychallenge(&p->skey, name, skeyprompt) == 0) {
 		char buf[256];
 		snprintf(buf, sizeof(buf), "%s\nS/Key challenge: ", skeyprompt);
 		data->server_msg = tac_strdup(buf);
